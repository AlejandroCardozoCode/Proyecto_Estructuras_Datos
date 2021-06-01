#include "grafo.h"
#include <algorithm>

void Grafo::iniciarMatrix(int tamano)
{
    matrixAristas.assign(tamano, std::vector<uint8_t>(tamano, 0));
}



void Grafo::insertarVertice(std::vector<std::string> listaPalabras) 
{
    verticesArreglo = listaPalabras;
}


int Grafo::buscarVerticePosicion(std::string verticeBuscar)
{
    std::vector<std::string>::iterator it = std::find(verticesArreglo.begin(), verticesArreglo.end(), verticeBuscar);
    if (it != verticesArreglo.end())
    {
        int index = std::distance(verticesArreglo.begin(), it);
        return index;
    }
    else
    {
        return -1;
    }
}

void Grafo::insetarArista(std::string puntoInicio, std::string puntoFinal, uint8_t costo)
{
    int posicionVerticeInicio, posicionVerticeFinal;
    posicionVerticeInicio = buscarVerticePosicion(puntoInicio);
    if (posicionVerticeInicio == -1)
    {
        return;
    }
    posicionVerticeFinal = buscarVerticePosicion(puntoFinal);
    if (posicionVerticeFinal == -1)
    {
        return;
    }
    if (matrixAristas[posicionVerticeInicio][posicionVerticeFinal] == 0)
    {
        matrixAristas[posicionVerticeInicio][posicionVerticeFinal] = costo;
        matrixAristas[posicionVerticeFinal][posicionVerticeInicio] = costo;
    }
}

std::string Grafo::buscarVerticePorPosicion(uint8_t posicion)
{
    typename std::vector<std::string>::iterator it = verticesArreglo.begin() + posicion;
    std::string aux = *it;
    return aux;
}

int Grafo::obtenerTamanoArregloVectores()
{
    return verticesArreglo.size();
}


void Grafo::imprimirMatrix() 
{
    for (int i = 0; i < verticesArreglo.size(); i++)
    {
        for (int j = 0; j < verticesArreglo.size(); j++)
        {
            std::cout <<"|" << matrixAristas[i][j] << "|";
        }
        std::cout << std::endl;
    }
    
}


std::vector<uint8_t> Grafo::encontrarVecinosVertice(uint8_t vertice)
{
    std::vector<uint8_t> vecinos;
    for (int i = 0; i < obtenerTamanoArregloVectores(); i++)
    {
        if (matrixAristas[i][(int)vertice] != 0)
        {
            vecinos.push_back(i);
        }
    }
    return vecinos;
}


void Grafo::imprimirVertices() 
{
    for (int i = 0; i < verticesArreglo.size(); i++)
    {
        std::cout << verticesArreglo[i] << std::endl;
    }
    
}



std::vector<std::string> Grafo::dijkstra(uint8_t inicio, uint8_t final)
{
    std::vector<uint8_t> arregloDistancias;        //dis
    std::vector<uint8_t> arregloPredecesores;      //pre
    std::vector<uint8_t> arregloVerticesVisitados; //S
    std::vector<uint8_t> arregloVerticesFuncion;   //Q
    std::vector<uint8_t> vecinosActual;
    std::vector<std::string> camino;
    bool caminoEncontrado = false;
    uint8_t posicionMenorCosto, posicionPuntoInicial, posicionPuntoFinal;
    std::string verticeMenorDistancia;
    posicionPuntoInicial = inicio;
    posicionPuntoFinal = final;

    for (int i = 0; i < obtenerTamanoArregloVectores(); i++)
    {
        arregloVerticesFuncion.push_back(i);
        if (i == posicionPuntoInicial)
        {
            arregloDistancias.push_back(0);
            arregloPredecesores.push_back(0);
        }
        else
        {
            arregloDistancias.push_back(INFINITY);
            arregloPredecesores.push_back(INFINITY);
        }
    }
    
    int nodoActual = 0;

    while (!arregloVerticesFuncion.empty())
    {

        posicionMenorCosto = buscarPosicionVerticeMenorCosto(arregloDistancias, arregloVerticesFuncion);
        if (posicionMenorCosto != -1)
        {
            arregloVerticesVisitados.push_back(arregloVerticesFuncion[posicionMenorCosto]);
            nodoActual = arregloVerticesFuncion[posicionMenorCosto];
            vecinosActual = encontrarVecinosVertice(nodoActual);

            for (int i = 0; i < vecinosActual.size(); i++)
            {
                if (arregloDistancias[vecinosActual[i]] > (matrixAristas[nodoActual][(int)vecinosActual[i]] + arregloDistancias[nodoActual]))
                {
                    arregloDistancias[vecinosActual[i]] = (matrixAristas[nodoActual][(int)vecinosActual[i]] + arregloDistancias[nodoActual]);
                    arregloPredecesores[vecinosActual[i]] = arregloVerticesFuncion[posicionMenorCosto];
                }
            }

            arregloVerticesFuncion.erase(arregloVerticesFuncion.begin() + posicionMenorCosto);
        }
        else
        {
            arregloVerticesFuncion.clear();
        }        
    }

    if (arregloDistancias[posicionPuntoFinal] == INFINITY)
    {
        std::cout << "No existe un camino para llegar desde el nodo inicial al nodo final " << std::endl;
        return camino;
    }

    std::string aux;
    camino.push_back(buscarVerticePorPosicion(final));
    std::cout << "El costo total es de: " << arregloDistancias[posicionPuntoFinal] << std::endl;
    while (!caminoEncontrado)
    {
        for (int i = 0; i < arregloDistancias.size(); i++)
        {
            if (i == posicionPuntoFinal)
            {
                aux = buscarVerticePorPosicion(arregloPredecesores[i]);
                if (arregloPredecesores[i] == posicionPuntoInicial)
                {
                    camino.push_back(aux);
                    caminoEncontrado = true;
                }
                else
                {
                    camino.push_back(aux);
                    posicionPuntoFinal = arregloPredecesores[i];
                }
            }
        }
    }
    std::reverse(camino.begin(), camino.end());
    std::cout << camino.size() << std::endl;
    return camino;
}


uint8_t Grafo::buscarPosicionVerticeMenorCosto(std::vector<uint8_t> arregloDistancias, std::vector<uint8_t> arregloVerticesFuncion)
{
    float posicionMenor = -1, valorMenor = INFINITY; 

    for (int j = 0; j < arregloVerticesFuncion.size(); j++)
    {
        if (arregloDistancias[arregloVerticesFuncion[j]] < valorMenor)
        {
            posicionMenor = j;
            valorMenor = arregloDistancias[arregloVerticesFuncion[j]];
        }
    }
    return posicionMenor;
}


void Grafo::fijarTamanoPalabras(uint8_t tamano) 
{
    tamanoPalabras = tamano;
}


uint8_t Grafo::obtenerTamanoPalabras() 
{
    return tamanoPalabras;
}   
