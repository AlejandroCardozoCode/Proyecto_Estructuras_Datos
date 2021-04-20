#ifndef __ARBOL_H__
#define __ARBOL_H__

#include "nodo.h"
#include <iostream>
#include <string>

template< class T >
class Tree {
  protected:
    Nodo<T>* raiz;
  public:
    Tree();
    ~Tree();
    bool esVacio();
    bool insertar1(std::string &linesInsertar);
    bool insertar2(std::string &linesInsertar, Nodo<T>* nodo);
    void posOrden();
    void imprimirArbol(Nodo<T>* nodo, int espacio);
    Nodo<T>* nodoRaiz();
};

#include "arbol.hxx"

#endif // __ARBOL_H__