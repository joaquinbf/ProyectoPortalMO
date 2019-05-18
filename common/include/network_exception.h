#ifndef __NETWORK_EXCEPTION_H__
#define __NETWORK_EXCEPTION_H__

#include "runtime_exception.h"

#define NETWORK_EXCEPTION(MSG) (NetworkException(MSG, __LINE__, \
                                                 __func__, __FILE__))

/* Representa a una excepcion relacionada a la comunicacion*/
class NetworkException: public RunTimeException {
public:
    /* Instancia una excepcion de comunicacion */
    NetworkException(const char *mensaje, int linea,
                     const char *funcion, const char *archivo);
};

#endif
