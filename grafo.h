#ifndef __GRAFO_H__
#define __GRAFO_H__

#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <math.h>
#include <set>
#include <unistd.h>
#include <string>



class Grafo
{
protected:
    std::vector<std::string> verticesArreglo;
    std::vector<std::vector<short>> matrixAristas;
    short tamanoPalabras;
public:
    void iniciarMatrix(int tamano);
    void insertarVertice(std::vector<std::string> listaPalabras);
    int buscarVerticePosicion(std::string verticeBuscar);
    void insetarArista(std::string puntoInicio, std::string puntoFinal, short costo);
    std::string buscarVerticePorPosicion(short posicion);
    int obtenerTamanoArregloVectores();
    void imprimirVertices();
    void imprimirMatrix();
    void fijarTamanoPalabras(short tamano);
    short obtenerTamanoPalabras();
    //Dijkstra
    std::vector<short> encontrarVecinosVertice(short vertice);
    std::vector<std::string> dijkstra(short inicio, short final);
    short buscarPosicionVerticeMenorCosto(std::vector<short> arregloDistancias, std::vector<short> arregloVerticesFuncion);
};

#include "grafo.hxx"

#endif // __GRAFO_H__