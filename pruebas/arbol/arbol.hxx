#include "arbol.h"
#include <queue>
#include <string>
#include <list>
#include <sstream>
#include <unistd.h>
template <class T>
Tree<T>::Tree()
{
  this->raiz = NULL;
}

template <class T>
Tree<T>::~Tree()
{
  if (this->raiz != NULL)
  {
    delete this->raiz;
    this->raiz = NULL;
  }
}

template <class T>
bool Tree<T>::esVacio()
{
  return this->raiz == NULL;
}

template <class T>
bool Tree<T>::insertar1(char &lineaInsertar)
{
  char raizS = ' ';
  this->raiz = new Nodo<char>(raizS);
  insertar2(lineaInsertar, raiz);

  return true;
}
template <class T>
bool Tree<T>::insertar2(char &lineaInsertar, Nodo<T> *nodo)
{

  std::vector<Nodo<T>> *hijosActual = nodo->obtenerHijos();
  Nodo<T> * nodoHijo = new Nodo<T>(lineaInsertar);
  hijosActual->push_back(*nodoHijo);
  nodoHijo = new Nodo<T>('d');
  hijosActual->push_back(*nodoHijo);
  nodo->fijarHijos(hijosActual);
  
  return true;
}





template <class T>
Nodo<T> *Tree<T>::nodoRaiz()
{
  return this->raiz;
}
