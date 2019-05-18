#ifndef __RUNTIME_EXCEPTION_H__
#define __RUNTIME_EXCEPTION_H__

#include <string>
#include <sstream>

class RunTimeException: public std::exception {
private:
    std::string mensaje;
    int linea;
    std::string funcion;
    std::string archivo;

public:
    /* Instancia una excepcion de run-time incando mediante un mensaje
     * los detalles de un error. */
    RunTimeException(const char *mensaje, int linea,
                     const char *funcion, const char *archivo);

    /* Devuelve una cadena con los detalles indicando linea,
     * funcion y archivo en donde ocurrio el error. */
    virtual const char *what() const throw();

    /* Devuelve un breve mensaje de error */
    virtual std::string getMensajeDeError() const;
};


#endif
