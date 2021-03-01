#include "diccionario.h"

Diccionario::Diccionario()
{
    nombre = "";
    std::deque <std::string> listaPalabras;
}
std::deque <std::string> Diccionario::obtenerPalabras() 
{
    return listaPalabras;
}

std::string Diccionario::obtenerNombre() 
{
    return nombre;
}
void Diccionario::fiajarNombre(std::string nombreP)
{
    nombre = nombreP;
}

void Diccionario::insertarPalabra(std::string palabraP)
{
    bool encontrado = false;
    std::deque<std::string>::iterator itPalabra;
    for (itPalabra = listaPalabras.begin(); itPalabra != listaPalabras.end(); itPalabra++)
    {
        if (*itPalabra == palabraP)
        {
            encontrado = true;
        }
    }
    if (!encontrado)
    {
        listaPalabras.push_back(palabraP);
    }

}

void Diccionario::imprimirDiccionario()
{
    std::cout << "Diccionario: " << nombre << "tiene las palabras" << std::endl;
    std::deque<std::string>::iterator itPalabra;
    for (itPalabra = listaPalabras.begin(); itPalabra != listaPalabras.end(); itPalabra++)
    {
        std::cout << *itPalabra << std::endl;
    }
}
