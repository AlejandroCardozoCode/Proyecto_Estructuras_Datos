#include "nodo.h"

template< class T >
Nodo<T>::Nodo() 
{
	this->hijos = NULL;
}

template< class T >
Nodo<T>::Nodo(T val) 
{
	this->hijos = NULL;
    this->dato = val;
}

template< class T >
Nodo<T>::~Nodo() 
{
    if (this->hijos != NULL) 
    {
        delete this->hijos;
        this->hijoDer = NULL;
    }
}

template< class T >
T Nodo<T>::obtenerDato() {
	return this->dato;
}

template< class T >
void Nodo<T>::fijarDato(T val) {
	this->dato = val;
}


template<class T>
std::vector<Nodo<T>>* Nodo<T>::obtenerHijos() 
{
    return this->hijos;
}



template<class T>
void Nodo<T>::fijarHijos(std::vector<Nodo<T>> * hijos) 
{
    this->hijos = hijos;
}


template< class T >
bool Nodo<T>::esHoja() {
  return (this->hijos == NULL);
}


// toca cambiarla 
template< class T >
void Nodo<T>::posOrden() {
  if (this->hijoIzq != NULL)
  {
    (this->hijoIzq)->posOrden();
  }
  if (this->hijoDer != NULL)
  {
    (this->hijoDer)->posOrden();
  }

  std::cout << this->dato << " ";
}


