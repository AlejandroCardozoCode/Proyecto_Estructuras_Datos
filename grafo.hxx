#include "grafo.h"
#include <algorithm>


void Grafo::insertarVertice(std::vector<std::string> palabra) 
{
    arregloVertices = palabra;
    lista.resize(palabra.size());
}


int Grafo::obtenerPosicionVertice(std::string verticeBuscar) 
{
    typename std::vector<std::string>::iterator it = std::find(arregloVertices.begin(), arregloVertices.end(), verticeBuscar);
    if (it != arregloVertices.end())
    {
        int index = std::distance(arregloVertices.begin(), it);
        return index;
    }
    else
    {
        return -1;
    }
}



int Grafo::existeConexion(int indiceInicio, int indiceFinal) 
{
    
    for(int i = 0; i < lista[indiceInicio].size(); i++)
    {
        if(lista[indiceInicio][i].posicion == indiceFinal)
        {
            return i;
        }
    }
    return -1;
}



void Grafo::insetarArista(std::string puntoInicio, std::string puntoFinal, int costo) 
{
    int posicionVerticeInicio, posicionVerticeFinal;
    posicionVerticeInicio = obtenerPosicionVertice(puntoInicio);
    if (posicionVerticeInicio == -1)
    {
        return;
    }
    posicionVerticeFinal = obtenerPosicionVertice(puntoFinal);
    if (posicionVerticeFinal == -1)
    {
        return;
    }
    if (existeConexion(posicionVerticeInicio, posicionVerticeFinal) == -1)
    {
        Conexiones aux;
        aux.posicion = posicionVerticeFinal;
        aux.peso = costo;
        lista[posicionVerticeInicio].push_back(aux);
        aux.posicion = posicionVerticeInicio;
        lista[posicionVerticeFinal].push_back(aux);
    }
    return;
}


std::string Grafo::obtenerVerticeDatoPorPosicion(int posicion) 
{
    typename std::vector<std::string>::iterator it = arregloVertices.begin() + posicion;
    std::string aux = *it;
    return aux;
}


int Grafo::obtenerTamanoArregloVectores() 
{
    return arregloVertices.size();
}


void Grafo::imprimirVertices() 
{
    for (int i = 0; i < arregloVertices.size(); i++)
    {
        std::cout << arregloVertices[i] << std::endl;
    }
}


void Grafo::imprimirConexiones() 
{
    for (int i = 0; i < lista.size(); i++)
    {
    std::cout << " la lista tiene un tamano de : " << lista.size() << " y en la posicion "<< i << " tiene " << lista[i].size() << " conexiones " << std::endl;
        for (int j = 0; i < lista[i].size(); j++)
        {
            std::cout << "ALJFLSJFLASJFL" << std::endl;
            std::string inicio, fin;
            std::cout << "El vertice " << obtenerVerticeDatoPorPosicion(i) << " tiene conexion con el vertice "  <<  obtenerVerticeDatoPorPosicion(lista[i][j].posicion) << std::endl;
        }
        
    }
}


void Grafo::fijarTamanoGrafo(int valor) 
{
    tamanoPalabrasGrafo = valor;
}



int Grafo::obtenerTamanoGrafo() 
{
    return tamanoPalabrasGrafo;
}




