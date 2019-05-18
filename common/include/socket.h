#ifndef __SOCKET_H__
#define __SOCKET_H__

/* Clase encargada de la comunicacion entre usuarios */
class Socket {
public:
    /* Envia todo el contenido de un buffer de tamanio len */
    virtual int sendAll(const char *buffer, int len) = 0;

    /* Recibe un contenido a un buffer de tamanio len. */
    virtual int recvAll(char *buffer, int len) = 0;
};

#endif
