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
Nodo<T>::~Nodo()
{
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

  return (this->hijos.empty());
}

// toca cambiarla
template <class T>
void Nodo<T>::posOrden()
{
}

template <class T>
void Nodo<T>::imprimirPrueba(Nodo<T> *nodo)
{
  std::vector<Nodo<char>> *hijosActual = nodo->obtenerHijos();
  std::vector<Nodo<char>> hijosMelos = *hijosActual;
  for (int count = 0; count < hijosMelos.size(); count++) //For Loop to Display All Products
  {
    std::cout << hijosMelos[count].obtenerDato() << std::endl;
  } 

  /*

  std::vector<Nodo<char>> *hijosActual = nodo->obtenerHijos();
  std::cout << hijosActual->begin()->dato << std::endl;

  */
}
