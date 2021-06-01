#ifndef __TADMAESTRO_H__
#define __TADMAESTRO_H__

#include "arbol.h"
#include "diccionario.h"
#include "grafo.h"

class TadMaestro
{
protected:
    std::vector<Diccionario> listaDiccionarios;
    std::vector<std::string> arbolesNormales, arbolesInversos;
    Grafo grafo;
public:
    std::vector<Diccionario> obtenerDiccionarios();
    std::vector<std::string> obtenerArbolNormales();
    std::vector<std::string> obtenerArbolInversos(); 
    Grafo obtenerGrafo();

    void fijarDiccionario(std::vector<Diccionario> dic);
    void fijarArbolNormales( std::vector<std::string> arbol);
    void fijarArbolInversos( std::vector<std::string> arbol);
    void fijarGrafo(Grafo grafoP);
};

#include "tadMaestro.hxx"

#endif // __TADMAESTRO_H__