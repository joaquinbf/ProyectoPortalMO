#include "../include/runtime_exception.h"
#include <string>
#include <sstream>

RunTimeException::RunTimeException(
    const char *mensaje, int linea, const char *funcion, const char *archivo):
    mensaje(mensaje), linea(linea), funcion(funcion), archivo(archivo) {}

const char *RunTimeException::what() const throw() {
   std::stringstream ss;
   ss << "error: " << mensaje << " en linea: " << linea
      << " en funcion: " << funcion << " en archivo: " << archivo;
   return ss.str().c_str();
}

std::string RunTimeException::getMensajeDeError() const {
    std::stringstream ss(this->mensaje);
    return ss.str();
}
