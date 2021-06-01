#include "tadMaestro.h"

std::vector<Diccionario> TadMaestro::obtenerDiccionarios()
{
    return listaDiccionarios;
}

std::vector<std::string> TadMaestro::obtenerArbolNormales()
{
    return arbolesNormales;
}

std::vector<std::string> TadMaestro::obtenerArbolInversos()
{
    return arbolesInversos;
}

Grafo TadMaestro::obtenerGrafo()
{
    return grafo;
}



void TadMaestro::fijarDiccionario(std::vector<Diccionario> dic) 
{
    listaDiccionarios = dic;
}


void TadMaestro::fijarArbolNormales(std::vector<std::string> arbol) 
{
    arbolesNormales = arbol;
}


void TadMaestro::fijarArbolInversos(std::vector<std::string> arbol) 
{
    arbolesInversos = arbol;
}


void TadMaestro::fijarGrafo(Grafo grafoP) 
{
    grafo = grafoP;
}



