#ifndef __UTILIDADES_H__
#define __UTILIDADES_H__

#include <iostream>

void impresionAyuda();
void impresionAyudaEspecifico(std::string);
int compararPalabra(std::string palabra1, std::string palabra2);
int palabrasPosiblesVerificacion(std::string cadena, std::string palabra, bool hayComodin);
int contarComodines(std::string cadena);

#include "utilidades.hxx"

#endif // __UTILIDADES_H__