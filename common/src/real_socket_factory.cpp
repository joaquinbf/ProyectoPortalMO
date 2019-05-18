#include "../include/real_socket_factory.h"
#include "../include/network_exception.h"
#include "../include/real_socket.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <iostream>

RealSocket RealSocketFactory::getClientSocket(
    const char* node, const char *service) {
    struct addrinfo hints;
    struct addrinfo *res;
    bool are_we_connected = false;
    int r;
    RealSocket socket(-1);

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = 0;

    if ((r = getaddrinfo(node, service, &hints, &res)) < 0) {
        throw NETWORK_EXCEPTION(gai_strerror(r));
    }

    for (struct addrinfo *ptr = res;
         ptr != NULL && !are_we_connected;
         ptr = ptr->ai_next) {
        try {
            RealSocket other_socket(ptr->ai_family,
                                ptr->ai_socktype,
                                ptr->ai_protocol);
            other_socket.connect(ptr->ai_addr, ptr->ai_addrlen);
            socket = std::move(other_socket);
            are_we_connected = true;
        } catch(const NetworkException &ex) {
            continue;
        }
    }

    freeaddrinfo(res);
    if (!are_we_connected) {
        throw NETWORK_EXCEPTION("Imposible conectarse");
    }

    return std::move(socket);
}

RealSocket RealSocketFactory::getServerSocket(const char *service) {
    struct addrinfo hints;
    struct addrinfo *res;
    bool are_we_connected = false;
    int r;
    RealSocket socket(-1);

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    if ((r = getaddrinfo(NULL, service, &hints, &res)) < 0) {
        throw NETWORK_EXCEPTION(gai_strerror(r));
    }

    for (struct addrinfo *ptr = res;
         ptr != NULL && !are_we_connected;
         ptr = ptr->ai_next) {
        try {
            RealSocket other_socket(ptr->ai_family,
                                ptr->ai_socktype,
                                ptr->ai_protocol);
            other_socket.reuseAddress();
            other_socket.bind(ptr->ai_addr, ptr->ai_addrlen);
            are_we_connected = true;
            socket = std::move(other_socket);
        } catch(const NetworkException &ex) {
            continue;
        }
    }

    freeaddrinfo(res);
    if (!are_we_connected) {
        throw NETWORK_EXCEPTION("Imposible conectarse");
    }

    return std::move(socket);
}
