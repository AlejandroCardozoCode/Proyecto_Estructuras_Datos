#include "nodo.h"

template <class T>
Nodo<T>::Nodo()
{
  this->hijos = new std::vector<Nodo<T>>;
}

template <class T>
Nodo<T>::Nodo(T val)
{
  this->hijos = new std::vector<Nodo<T>>;
  this->dato = val;
}

template <class T>
T Nodo<T>::obtenerDato()
{
  return this->dato;
}

template <class T>
void Nodo<T>::fijarDato(T val)
{
  this->dato = val;
}

template <class T>
std::vector<Nodo<T>> *Nodo<T>::obtenerHijos()
{
  return this->hijos;
}

template <class T>
void Nodo<T>::fijarHijos(std::vector<Nodo<T>> *hijos)
{
  this->hijos = hijos;
}

template <class T>
bool Nodo<T>::esHoja()
{
  std::vector<Nodo<T>> hijo = this->obtenerHijos();
  return hijo.empty();
}



