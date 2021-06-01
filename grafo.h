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
#include <stdint.h>



class Grafo
{
protected:
    std::vector<std::string> verticesArreglo;
    std::vector<std::vector<uint8_t>> matrixAristas;
    uint8_t tamanoPalabras;
public:
    void iniciarMatrix(int tamano);
    void insertarVertice(std::vector<std::string> listaPalabras);
    int buscarVerticePosicion(std::string verticeBuscar);
    void insetarArista(std::string puntoInicio, std::string puntoFinal, uint8_t costo);
    std::string buscarVerticePorPosicion(uint8_t posicion);
    int obtenerTamanoArregloVectores();
    void imprimirVertices();
    void imprimirMatrix();
    void fijarTamanoPalabras(uint8_t tamano);
    uint8_t obtenerTamanoPalabras();
    //Dijkstra
    std::vector<uint8_t> encontrarVecinosVertice(uint8_t vertice);
    std::vector<std::string> dijkstra(uint8_t inicio, uint8_t final);
    uint8_t buscarPosicionVerticeMenorCosto(std::vector<uint8_t> arregloDistancias, std::vector<uint8_t> arregloVerticesFuncion);
};

#include "grafo.hxx"

#endif // __GRAFO_H__