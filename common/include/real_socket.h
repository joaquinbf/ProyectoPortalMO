#ifndef __REAL_SOCKET_H__
#define __REAL_SOCKET_H__

#include "socket.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <arpa/inet.h>

/* Clase encargada de enviar y recibir mensajes entre dos usuarios */
class RealSocket: public Socket {
private:
    int skt;

public:
    /* Instancia un socket en base a un socket file destriptor */
    explicit RealSocket(int skt);

    /* Instancia un socket en base al domain, type y protocolo datos */
    RealSocket(int domain, int type, int protocol);

    /* Constructor de movimiento */
    RealSocket(RealSocket&& other);

    /* Asignacion por movimiento */
    RealSocket& operator=(RealSocket&& other);

    /* Libera los recursos utilizados */
    ~RealSocket();

    /* Conecta el socket a la direccion indicada en addr */
    void connect(const struct sockaddr *addr, socklen_t addrlen);

    /* Permite reutilizar la direccion dada */
    void reuseAddress();

    /* Cierra una o ambas partes de la conexion de sockets indicadas en how.
     * how es una constante con valores SHUT_RD, SHUT_WR, SHUT_RDWR. */
    void shutdown(int how);

    /* Cierra futuras recepciones */
    void shutdownRD();

    /* Cierra futuras transmisiones */
    void shutdownWR();

    /* Cierra futuras recepciones y transmisiones */
    void shutdownRDWR();

    /* Cierra el socket */
    void close();

    /* Asigna la direccion dada en addr al socket */
    void bind(const struct sockaddr *addr, socklen_t addrlen);

    /* Marca al socket como pasivo y backlog indica la maxima longitud de la
     * cola de conexiones pendientes */
    void listen(int backlog);

    /* Extrae el primer pedido de socket escuchantes pendiente.
     * addr contiene la informacion del peer socket */
    RealSocket accept(struct sockaddr *addr, socklen_t *addrlen);

    /* Extrae el primer pedido de socket escuchantes pendiente */
    RealSocket accept();

    /* Envia todo el contenido de un buffer de tamanio size */
    virtual int sendAll(const char *buf, int size);

    /* Recibe un contenido a un buffer de tamanio size. */
    virtual int recvAll(char *buf, int size);
};

#endif
