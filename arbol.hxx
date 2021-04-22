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
bool Tree<T>::insertar1(std::string &lineaInsertar)
{
  char raizS = ' ';
  if (this->raiz == NULL)
  {
    this->raiz = new Nodo<char>(raizS);
    insertar2(lineaInsertar, raiz);
  }
  else
  {
    insertar2(lineaInsertar, raiz);
  }
  return true;
}
template <class T>
bool Tree<T>::insertar2(std::string &lineaInsertar, Nodo<T> *nodo)
{
  if (!lineaInsertar.empty())
  {
    std::vector<Nodo<T>> *hijosActual = nodo->obtenerHijos();
    std::vector<Nodo<T>> hijosActualValor = *hijosActual;
    int posicion = 0;
    Nodo<char> *nodoPosicion;
    bool encontrado = false;

    for (int i = 0; i < hijosActualValor.size(); i++)
    {
      if (hijosActualValor[i].obtenerDato() == lineaInsertar[0])
      {
        posicion = i;
        encontrado = true;
      }
    }

    if (encontrado)
    {
      nodoPosicion = &hijosActualValor[posicion];
      lineaInsertar.erase(0, 1);
      insertar2(lineaInsertar, nodoPosicion);
    }

    else
    {
      Nodo<T> *nodoHijo = new Nodo<T>(lineaInsertar[0]);
      hijosActual->push_back(*nodoHijo);
      hijosActualValor = *hijosActual;
      nodo->fijarHijos(hijosActual);
      for (int i = 0; i < hijosActualValor.size(); i++)
      {
        if (hijosActualValor[i].obtenerDato() == lineaInsertar[0])
        {
          posicion = i;
          encontrado = true;
        }
      }
      nodoPosicion = &hijosActualValor[posicion];
      lineaInsertar.erase(0, 1);
      insertar2(lineaInsertar, nodoPosicion);
    }
  }
  return true;
}

template <class T>
Nodo<T> *Tree<T>::nodoRaiz()
{
  return this->raiz;
}
