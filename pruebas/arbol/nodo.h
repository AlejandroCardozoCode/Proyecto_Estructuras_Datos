#ifndef __NODO_H__
#define __NODO_H__

#include <iostream>
#include <string>
#include <list>
#include <vector>

template< class T >
class Nodo {
  public:
    T dato;
    std::vector<Nodo<T>> *hijos;
  public:
    Nodo();
    Nodo(T val);
    ~Nodo();
    T obtenerDato();
    void fijarDato(T val);
    std::vector<Nodo<T>>* obtenerHijos();
    void fijarHijos(std::vector<Nodo<T>>* hijos);
    bool esHoja();
    void posOrden();
    void imprimirPrueba(Nodo<T> * nodo);
};


#include "nodo.hxx"


#endif // __NODO_H__