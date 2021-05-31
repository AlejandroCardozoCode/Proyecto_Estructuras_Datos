#include "arbol.h"
#include <queue>
#include <string>
#include <list>
#include <sstream>
#include <unistd.h>
#include <fstream>
#include <cstring>

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

template <class T>
Nodo<T> *Tree<T>::encontrarNodo(std::string &copiaPrefijo, Nodo<T> *nodo)
{
  Nodo<T> *nodoFinal = new Nodo<T>();
  Nodo<T> prueba;
  std::vector<Nodo<T>> *hijosActual = nodo->obtenerHijos();
  std::vector<Nodo<T>> hijosValor = *hijosActual;
  int posicion;
  bool encontrado = false;

  if (!copiaPrefijo.empty())
  {
    for (int i = 0; i < hijosValor.size(); i++)
    {
      if (hijosValor[i].obtenerDato() == copiaPrefijo[0])
      {
        posicion = i;
        encontrado = true;
      }
    }

    if (encontrado)
    {
      copiaPrefijo.erase(0, 1);
      nodoFinal->fijarDato(hijosValor[posicion].obtenerDato());
      nodoFinal->fijarHijos(hijosValor[posicion].obtenerHijos());
      nodoFinal = encontrarNodo(copiaPrefijo, nodoFinal);
      return nodoFinal;
    }

    if (!encontrado)
    {
      return NULL;
    }
  }

  return nodo;
}

template <class T>
void Tree<T>::imprimirHijos(Nodo<T> *nodo, std::string palabraS, std::string nombreArchivo, int modo)
{
  std::vector<Nodo<T>> *hijosActual = nodo->obtenerHijos();
  std::vector<Nodo<T>> hijosValor = *hijosActual;
  palabraS = palabraS + nodo->obtenerDato();
  std::ifstream archivo;
  std::string linea;
  int puntaje = 0;
  archivo.open(nombreArchivo);
  if (archivo.is_open())
  {
    while (std::getline(archivo, linea))
    {
      if (modo == 1)
      {
        std::reverse(linea.begin(), linea.end());
      }

      if (linea.compare(palabraS) == 0)
      {
        for (int i = 0; i < palabraS.size(); i++)
        {
            puntaje += calcularPuntos(palabraS[i]);
        }
        std::cout << palabraS << " tam: " << palabraS.size() << " puntaje: " << puntaje << std::endl;
      }
    }
    archivo.close();
  }

  for (int i = 0; i < hijosValor.size(); i++)
  {
    Nodo<T> *nuevoNodo = &hijosValor[i];
    imprimirHijos(nuevoNodo, palabraS, nombreArchivo, modo);
  }
  return;
}

template <class T>
void Tree<T>::prefijo(std::string &prefijo, std::string nombreArchivo)
{
  Nodo<T> *raiz = nodoRaiz();
  Nodo<T> *nodoFinal = new Nodo<T>();
  std::string copiaPrefijo = prefijo, palabraS = prefijo;
  palabraS.pop_back();
  nodoFinal = encontrarNodo(copiaPrefijo, raiz);

  if (nodoFinal == NULL)
  {
    std::cout << "El prefijo " << prefijo << " no pudo encontrarse en el diccionario " << std::endl;
  }

  else
  {
    Nodo<T> nodoFinalValor = *nodoFinal;
    std::cout << "Las palabras que inician con este prefijo son:  " << std::endl;
    imprimirHijos(nodoFinal, palabraS, nombreArchivo, 0);
  }
  return;
}

template <class T>
void Tree<T>::sufijo(std::string &sufijo, std::string nombreArchivo)
{
  Nodo<T> *raiz = nodoRaiz();
  Nodo<T> *nodoFinal = new Nodo<T>();
  std::string copiaPrefijo = sufijo, palabraS = sufijo;
  palabraS.pop_back();
  nodoFinal = encontrarNodo(copiaPrefijo, raiz);

  if (nodoFinal == NULL)
  {
    std::cout << "El sufijo " << sufijo << " no pudo encontrarse en el diccionario " << std::endl;
  }

  else
  {
    Nodo<T> nodoFinalValor = *nodoFinal;
    std::cout << "Las palabras que inician con este sufijo son:  " << std::endl;
    imprimirHijos(nodoFinal, palabraS, nombreArchivo, 1);
  }
  return;
}

template <class T>
int Tree<T>::calcularPuntos(char letra)
{
  std::string pun1, pun2, pun3, pun4, pun8, pun10;
  pun1 = "eaionrtlsu";
  pun2 = "dg";
  pun3 = "bcmp";
  pun4 = "fhvwy";
  pun8 = "jx";
  pun10 = "qz";
  if (letra == 'k')
    return 5;
  for (int i = 0; i < pun1.size(); i++)
  {
    if (pun1[i] == letra)
    {
      return 1;
    }
    else if (pun2[i] == letra)
    {
      return 2;
    }
    else if (pun3[i] == letra)
    {
      return 3;
    }
    else if (pun4[i] == letra)
    {
      return 4;
    }
    else if (pun8[i] == letra)
    {
      return 8;
    }
    else if (pun10[i] == letra)
    {
      return 10;
    }
  }
  return -1;
}
