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
    std::vector<std::vector<float>> matrixAristas;
public:
    void iniciarMatrix(int tamano);
    void insertarVertice(std::vector<std::string> listaPalabras);
    int buscarVerticePosicion(std::string verticeBuscar);
    void insetarArista(std::string puntoInicio, std::string puntoFinal, float costo);
    std::string buscarVerticePorPosicion(float posicion);
    int obtenerTamanoArregloVectores();
    void imprimirVertices();
    void imprimirMatrix();
    //Dijkstra
    std::vector<float> encontrarVecinosVertice(float vertice);
    std::vector<std::string> dijkstra(float inicio, float final);
    float buscarPosicionVerticeMenorCosto(std::vector<float> arregloDistancias, std::vector<float> arregloVerticesFuncion);
};

#include "grafo.hxx"

#endif // __GRAFO_H__