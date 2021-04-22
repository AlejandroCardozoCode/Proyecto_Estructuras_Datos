#include "diccionario.h"

Diccionario::Diccionario()
{
    nombre = "";
    std::deque<std::string> listaPalabras;
}
std::deque<std::string> Diccionario::obtenerPalabras()
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
    listaPalabras.push_back(palabraP);
}

void Diccionario::verificarRepetidas()
{
    sort(listaPalabras.begin(), listaPalabras.end());
    listaPalabras.erase(unique(listaPalabras.begin(), listaPalabras.end()), listaPalabras.end());
}

bool Diccionario::existePalabraInv(std::string palabra)
{
    std::reverse(palabra.begin(), palabra.end());
    std::deque<std::string>::iterator itPalabra;
    for (itPalabra = listaPalabras.begin(); itPalabra != listaPalabras.end(); itPalabra++)
    {
        if (*itPalabra == palabra)
        {
            return true;
        }
    }
    return false;
}
bool Diccionario::existePalabra(std::string palabra)
{
    std::deque<std::string>::iterator itPalabra;
    for (itPalabra = listaPalabras.begin(); itPalabra != listaPalabras.end(); itPalabra++)
    {
        if (*itPalabra == palabra)
        {
            return true;
        }
    }
    return false;
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
