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

struct Conexiones
{
    int posicion;
    int peso;

};


class Grafo
{
protected:
    std::vector<std::string> arregloVertices;
    std::vector<std::vector<Conexiones>> lista;
    int tamanoPalabrasGrafo;
public:
    void insertarVertice(std::vector<std::string> palabra);
    int obtenerPosicionVertice(std::string verticeBuscar);
    int existeConexion(int indiceInicio, int indiceFinal);
    void insetarArista(std::string puntoInicio, std::string puntoFinal, int costo);
    std::string obtenerVerticeDatoPorPosicion (int posicion);
    int obtenerTamanoArregloVectores();
    void imprimirVertices(); 
    void imprimirConexiones();
    void fijarTamanoGrafo(int valor);
    int obtenerTamanoGrafo();
    std::vector<std::string> obtenerArregloVertices();

};

#include "grafo.hxx"

#endif // __GRAFO_H__