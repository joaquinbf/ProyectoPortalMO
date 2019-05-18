#ifndef __REAL_SOCKET_FACTORY_H__
#define __REAL_SOCKET_FACTORY_H__

#include "real_socket.h"

/* Clase encargada de la creacion de sockets */
class RealSocketFactory {
public:
        /* Instancia un socket cliente conectado al nodo y servicio indicado */
    RealSocket getClientSocket(const char *node, const char *service);

    /* Instancia un socket servidor enlazado al nodo indicado */
    RealSocket getServerSocket(const char *node);
};

#endif
