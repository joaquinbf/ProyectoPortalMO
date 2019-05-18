#include "../include/network_exception.h"

NetworkException::NetworkException(
    const char *mensaje, int linea,
    const char *funcion, const char *archivo):
    RunTimeException(mensaje, linea, funcion, archivo) {
}
