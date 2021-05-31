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
    Nodo<T> * encontrarNodo(std::string &copiaPrefijo, Nodo<T> *nodo);
    void prefijo(std::string &prefijo, std::string nombreArchivo);
    void sufijo(std::string &sufijo, std::string nombreArchivo);
    Nodo<T>* nodoRaiz();
    void imprimirHijos(Nodo<T> *nodo, std::string palabraS, std::string nombreArchivo, int modo);
    int calcularPuntos (char letra);
    
};

#include "arbol.hxx"

#endif // __ARBOL_H__