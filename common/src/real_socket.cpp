#include "../include/real_socket.h"
#include "../include/network_exception.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <arpa/inet.h>

RealSocket::RealSocket(): skt(-1) {
}

RealSocket::RealSocket(int skt) {
    this->skt = skt;
}

RealSocket::RealSocket(int domain, int type, int protocol) {
    if ((this->skt = socket(domain, type, protocol)) < 0) {
        throw NetworkException(strerror(errno), __LINE__, __func__, __FILE__);
    }
}

RealSocket::RealSocket(RealSocket&& other) {
    this->skt = other.skt;
    other.skt = -1;
}

RealSocket& RealSocket::operator=(RealSocket&& other) {
    if (this == &other) {
        return *this;
    }
    this->skt = other.skt;
    other.skt = -1;
    return *this;
}

RealSocket::~RealSocket() {
    this->close();
}

void RealSocket::connect(const struct sockaddr *addr, socklen_t addrlen) {
    int r;
    if ((r = ::connect(this->skt, addr, addrlen)) < 0) {
        throw NETWORK_EXCEPTION(strerror(errno));
    }
}

void RealSocket::reuseAddress() {
    int val = 1;
    int r = setsockopt(this->skt, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));
    if (r < 0) {
        throw NETWORK_EXCEPTION(strerror(errno));
    }
}

void RealSocket::shutdown(int how) {
    int r;
    if ((r = ::shutdown(this->skt, how)) < 0) {
        throw NETWORK_EXCEPTION(strerror(errno));
    }
}

void RealSocket::shutdownRD() {
    this->shutdown(SHUT_RD);
}

void RealSocket::shutdownWR() {
    this->shutdown(SHUT_WR);
}

void RealSocket::shutdownRDWR() {
    this->shutdown(SHUT_RDWR);
}

void RealSocket::close() {
    if (this->skt >= 0) {
        ::close(this->skt);
    }
}

void RealSocket::bind(const struct sockaddr *addr, socklen_t addrlen) {
    int r;
    if ((r = ::bind(this->skt, addr, addrlen)) < 0) {
        throw NETWORK_EXCEPTION(strerror(errno));
    }
}

void RealSocket::listen(int backlog) {
    int r;
    if ((r = ::listen(this->skt, backlog)) < 0) {
        throw NETWORK_EXCEPTION(strerror(errno));
    }
}

RealSocket RealSocket::accept(struct sockaddr *addr, socklen_t *addrlen) {
    int r;
    if ((r = ::accept(this->skt, addr, addrlen)) < 0) {
        throw NETWORK_EXCEPTION(strerror(errno));
    }
    return std::move(RealSocket(r));
}

RealSocket RealSocket::accept() {
    return std::move(this->accept(NULL, NULL));
}

int RealSocket::sendAll(const char *buf, int size) {
    int sent = 0;
    int s = 0;
    bool is_the_socket_valid = true;

    while (sent < size && is_the_socket_valid) {
        s = ::send(this->skt, &buf[sent], size - sent, MSG_NOSIGNAL);
        if (s == -1) {
            throw NETWORK_EXCEPTION(strerror(errno));
        } else if (s == 0) {
            is_the_socket_valid = false;
        } else {
            sent += s;
        }
    }

    return sent;
}

int RealSocket::recvAll(char *buf, int size) {
    int received = 0;
    int s = 0;
    bool is_the_socket_valid = true;

    while (received < size && is_the_socket_valid) {
        s = ::recv(this->skt, &buf[received], size - received, 0);
        if (s == -1) {
            throw NETWORK_EXCEPTION(strerror(errno));
        } else if (s == 0) {
            is_the_socket_valid = false;
        } else {
            received += s;
        }
    }

    return received;
}
