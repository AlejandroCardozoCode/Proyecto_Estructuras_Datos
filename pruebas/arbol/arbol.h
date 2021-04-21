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
    bool insertar1(char &linesInsertar);
    bool insertar2(char &linesInsertar, Nodo<T>* nodo);
    Nodo<T>* nodoRaiz();
    
};

#include "arbol.hxx"

#endif // __ARBOL_H__