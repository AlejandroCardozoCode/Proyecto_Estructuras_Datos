#include "arbol.h"
#include <queue>
#include <string>
#include <list>
#include <sstream>
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
  std::stringstream varChar;
  varChar << lineaInsertar[0];
  int raizS;
  varChar >> raizS;
  this->raiz = new Nodo<int>(raizS);
  lineaInsertar.erase(0,1);
  insertar2(lineaInsertar, raiz);
  return true;
}
template <class T>
bool Tree<T>::insertar2(std::string &lineaInsertar, Nodo<T>* nodo)
{
  int hijoExtDerVar, hijoExtIzqVar, hijoDerVar, hijoIzqVar;
  std::stringstream varCharhijoExtIzqVar, varCharhijoIzqVar, varCharhijoDerVar, varCharhijoExtDerVar;

  varCharhijoExtIzqVar << lineaInsertar[0];
  varCharhijoExtIzqVar >> hijoExtIzqVar;
  Nodo<int> *nuevohijoExtIzqVar = new Nodo<int>(hijoExtIzqVar);
  nodo->fijarHijoExtIzq(nuevohijoExtIzqVar);
  lineaInsertar.erase(0,1);
  if (nodo->obtenerHijoExtIzq()->obtenerDato() == 2)
  {
    insertar2(lineaInsertar, nodo->obtenerHijoExtIzq());
  }

  varCharhijoIzqVar<< lineaInsertar[0];
  varCharhijoIzqVar >> hijoIzqVar;
  Nodo<int> *nuevohijoIzqVar = new Nodo<int>(hijoIzqVar);
  nodo->fijarHijoIzq(nuevohijoIzqVar);
  lineaInsertar.erase(0,1);
  if (nodo->obtenerHijoIzq()->obtenerDato() == 2)
  {
    insertar2(lineaInsertar, nodo->obtenerHijoIzq());
  }

  varCharhijoDerVar << lineaInsertar[0];
  varCharhijoDerVar >> hijoDerVar;
  Nodo<int> *nuevohijoDerVar = new Nodo<int>(hijoDerVar);
  nodo->fijarHijoDer(nuevohijoDerVar);
  lineaInsertar.erase(0,1);
  if (nodo->obtenerHijoDer()->obtenerDato() == 2)
  {
    insertar2(lineaInsertar, nodo->obtenerHijoDer());
  }

  varCharhijoExtDerVar << lineaInsertar[0];
  varCharhijoExtDerVar >> hijoExtDerVar;
  Nodo<int> *nuevohijoExtDerVar = new Nodo<int>(hijoExtDerVar);
  nodo->fijarHijoExtDer(nuevohijoExtDerVar);
  lineaInsertar.erase(0,1);
  if (nodo->obtenerhijoExtrDer()->obtenerDato() == 2)
  {
    insertar2(lineaInsertar, nodo->obtenerhijoExtrDer());
  }
  
  return true;
}


template <class T>
void Tree<T>::posOrden()
{
  if (!this->esVacio())
    (this->raiz)->posOrden();
}


template <class T>
void Tree<T>::imprimirArbol(Nodo<T> *nodo, int espacio)
{
  int c;
  std::string aux;

  if (nodo == NULL)
    return;

  aux = nodo->obtenerDato();
  c = aux.size();
  espacio += 20;
  imprimirArbol(nodo->obtenerhijoExtrDer(), espacio);
  std::cout << std::endl;
  for (int i = 20; i < espacio; i++)
  {

    if (i == espacio - (10 - (c - 1)))
    {

      std::cout << "|";
    }
    if (i > (espacio - (9 - (c - 1))))
    {
      std::cout << "-";
    }
    else
      std::cout << " ";
  }
  if (aux.size() < 0)
    std::cout << ">>" << nodo->obtenerDato() << "|\n";
  else
    std::cout << ">>" << nodo->obtenerDato() << " |\n";
  imprimirArbol(nodo->obtenerHijoExtIzq(), espacio);
}


template <class T>
Nodo<T> *Tree<T>::nodoRaiz()
{
  return this->raiz;
}
