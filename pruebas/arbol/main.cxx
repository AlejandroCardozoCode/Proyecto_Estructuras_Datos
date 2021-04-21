// proyecto de estructuras
// Diego Alejandro Cardozo Rojas, Brayan Estiben Giraldo Lopoez, David Alejandro Antolinez Socha

#include <iostream>
#include <fstream>
#include <deque>
#include <algorithm>
#include "arbol.h"

int main(int argc, char *argv[])
{
    /*
    Tree<char> arbol;
    char linea = 'h';

    arbol.insertar1(linea);
    std::cout << "penito" << std::endl;

    Nodo<char> * nodo = arbol.nodoRaiz();
    nodo->imprimirPrueba(nodo);
    */

    char a = 'c';
    std::string hola = "PeneLOpe";
    for (int i = 0; i < hola.length(); i++)
    {
        hola[i] = tolower(hola[i]);
    }
    std::cout << hola << std::endl;
}