#ifndef __DICCIONARIO_H__
#define __DICCIONARIO_H__
#include <iostream>
#include <algorithm>
#include <deque>

class Diccionario
{
    //atributos
    protected:
    std::string nombre;
    std::vector <std::string> listaPalabras;
    //funciones
    public:
    Diccionario();
    std::string obtenerNombre();
    std::vector <std::string> obtenerPalabras();
    void fiajarNombre(std::string nombreP);
    bool existePalabra(std::string palabra);
    void insertarPalabra(std::string palabraP);
    bool existePalabraInv(std::string palabra);
    void verificarRepetidas();
    void imprimirDiccionario();

};

#include "diccionario.hxx"

#endif // __DICCIONARIO_H__