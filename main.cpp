// proyecto de estructuras
// Diego Alejandro Cardozo Rojas, Brayan Estiben Giraldo Lopoez, David Alejandro Antolinez Socha

#include <iostream>
#include <fstream>
#include <deque>
#include "diccionario.h"
#include <algorithm>

bool verificarPalabra(std::string linea)
{
    bool verificacionPalabra = true;
    for (int i = 0; i < linea.size(); i++)
    {
        if (!isalpha(linea[i]))
        {
            verificacionPalabra = false;
        }
    }
    return verificacionPalabra;
}
void comandoAyudaEspecifico(std::string valor)
{
    if (valor.compare("inicializar") == 0)
    {
        std::cout << "- inicializar: llame la funcion y seguidamente el arichivo de texto" << std::endl;
    }
    else if (valor.compare("iniciar_inverso") == 0)
    {
        std::cout <<"- iniciar_inverso: llame la funcion y seguidamente el arichivo de texto" << std::endl;
    }
    else if (valor.compare("puntaje") == 0)
    {
        std::cout <<"- puntaje: llame la funcion y seguidamente una palabra" << std::endl;
    }
    else if (valor.compare("salir") == 0)
    {
        std::cout << "- salir" << std::endl;
    }
    else if (valor.compare("iniciar_arbol") == 0)
    {
        std::cout << "- iniciar_arbol: llame la funcion y seguidamente un archivo de texto" << std::endl;
    }
    else if (valor.compare("iniciar_arbol_inverso") == 0)
    {
        std::cout << "- iniciar_arbol_inverso: llame la funcion y seguidamente un archivo de texto" << std::endl;
    }
    else if (valor.compare("palabras_por_prefijo") == 0)
    {
        std::cout << "- palabras_por_prefijo: llame la funcion y seguidamente prefijo" << std::endl;
    }
    else if (valor.compare("palabras_por_sufijo") == 0)
    {
        std::cout << "- palabras_por_sufijo: llame la funcion y seguidamente sufijo" << std::endl;
    }
    else if (valor.compare("grafo_de_palabras") == 0)
    {
        std::cout << "- grafo_de_palabras: llame la funcion" << std::endl;
    }
    else if (valor.compare("posibles_palabras") == 0)
    {
        std::cout << "- posibles_palabras: llame la funcion y seguidamente una cadena de letras" << std::endl;
    }
    else
    {
        std::cout << "El comando ingresado no existe" << std::endl;
    }
}
void comandoAyuda()
{
    std::cout << "comandos validos:" << std::endl
              << "- inicializar: llame la funcion y seguidamente el arichivo de texto" << std::endl
              << "- iniciar_inverso: llame la funcion y seguidamente el arichivo de texto" << std::endl
              << "- puntaje: llame la funcion y seguidamente una palabra" << std::endl
              << "- salir" << std::endl
              << "- iniciar_arbol: llame la funcion y seguidamente un archivo de texto" << std::endl
              << "- iniciar_arbol_inverso: llame la funcion y seguidamente un archivo de texto" << std::endl
              << "- palabras_por_prefijo: llame la funcion y seguidamente prefijo" << std::endl
              << "- palabras_por_sufijo: llame la funcion y seguidamente sufijo" << std::endl
              << "- grafo_de_palabras: llame la funcion" << std::endl
              << "- posibles_palabras: llame la funcion y seguidamente una cadena de letras" << std::endl;
    return;
}

void comandoInicializar(std::string valor, std::deque<Diccionario> &listaDiccionarios)
{
    std::cout << "comando inicializar correcto" << std::endl;
    if (valor.compare(" ") == 0 || valor.compare("") == 0)
    {
        std::cout << "Error numero de parametros insuficiente, por favor llame la funcion y seguidamente el arichivo de texto " << std::endl;
    }

    std::string linea, nombreArchivo = valor;
    std::ifstream archivo;
    int lineasArchivo = 0;
    bool verificacionPalabra = true;
    Diccionario diccionarioAux;
    std::deque<std::string> palabrasAux;

    std::deque<Diccionario>::iterator itDiccionario;

    for (itDiccionario = listaDiccionarios.begin(); itDiccionario != listaDiccionarios.end(); itDiccionario++)
    {
        if (itDiccionario->obtenerNombre() == nombreArchivo)
        {
            std::cout << "El diccionario ya ha sido inicializado." << std::endl;
            return;
        }
    }

    diccionarioAux.fiajarNombre(nombreArchivo);
    archivo.open(nombreArchivo);
    if (archivo.is_open())
    {
        while (std::getline(archivo, linea))
        {
            verificacionPalabra = verificarPalabra(linea);
            if (verificacionPalabra)
            {
                diccionarioAux.insertarPalabra(linea);
            }
        }
        std::cout << "El diccionario se ha inicializado correctamente " << std::endl;
        archivo.close();
    }
    else
    {
        std::cout << "El archivo " << nombreArchivo << " no existe o no puede ser leído." << std::endl;
    }
    listaDiccionarios.push_back(diccionarioAux);
    return;
}

void comandoInicializarInverso(std::string valor, std::deque<Diccionario> &listaDiccionarios)
{
    std::cout << "comando iniciar_inverso correcto" << std::endl;
    if (valor.compare(" ") == 0 || valor.compare("") == 0)

    {
        std::cout << "Error numero de parametros insuficiente, por favor llame la funcion y seguidamente el arichivo de texto " << std::endl;
    }

    std::string linea, nombreArchivo = valor;
    std::ifstream archivo;
    int lineasArchivo = 0;
    bool verificacionPalabra = true;
    Diccionario diccionarioAux;
    std::deque<std::string> palabrasAux;

    std::deque<Diccionario>::iterator itDiccionario;

    for (itDiccionario = listaDiccionarios.begin(); itDiccionario != listaDiccionarios.end(); itDiccionario++)
    {
        if (itDiccionario->obtenerNombre() == nombreArchivo)
        {
            std::cout << "El diccionario inverso ya ha sido inicializado." << std::endl;
            return;
        }
    }

    diccionarioAux.fiajarNombre(nombreArchivo);
    archivo.open(nombreArchivo);
    if (archivo.is_open())
    {
        while (std::getline(archivo, linea))
        {
            verificacionPalabra = verificarPalabra(linea);
            if (verificacionPalabra)
            {
                std::reverse(linea.begin(), linea.end());
                diccionarioAux.insertarPalabra(linea);
            }
        }
        std::cout << "El diccionario inverso se ha inicializado correctamente " << std::endl;
        archivo.close();
    }
    else
    {
        std::cout << "El archivo " << nombreArchivo << " no existe o no puede ser leído." << std::endl;
    }
    listaDiccionarios.push_back(diccionarioAux);

    return;
}

int puntos(char letra)
{
    std::string pun1, pun2, pun3, pun4, pun8, pun10;
    pun1 = "eaionrtlsu";
    pun2 = "dg";
    pun3 = "bcmp";
    pun4 = "fhvwy";
    pun8 = "jx";
    pun10 = "qz";
    if (letra == 'k')
        return 5;
    for (int i = 0; i < pun1.size(); i++)
    {
        if (pun1[i] == letra)
        {
            return 1;
        }
        else if (pun2[i] == letra)
        {
            return 2;
        }
        else if (pun3[i] == letra)
        {
            return 3;
        }
        else if (pun4[i] == letra)
        {
            return 4;
        }
        else if (pun8[i] == letra)
        {
            return 8;
        }
        else if (pun10[i] == letra)
        {
            return 10;
        }
    }
    return -1;
}
void comandoPuntaje(std::string valor, std::deque<Diccionario> &listaDiccionarios)
{
    int puntaje = 0;
    std::deque<Diccionario>::iterator itDiccionario;
    std::cout << "comando puntaje correcto" << std::endl;
    if (valor.compare(" ") == 0 || valor.compare("") == 0)
    {
        std::cout << "Error numero de parametros insuficiente, por favor llame la funcion y seguidamente una palabra " << std::endl;
    }
    if (!verificarPalabra(valor))
    {
        std::cout << "La palabra contiene símbolos inválidos";
        return;
    }
    for (itDiccionario = listaDiccionarios.begin(); itDiccionario != listaDiccionarios.end(); itDiccionario++)
    {
        if (itDiccionario->existePalabraInv(valor) || itDiccionario->existePalabra(valor))
        {
            for (int i = 0; i < valor.size(); i++)
            {
                puntaje += puntos(valor[i]);
            }
        }
        else
        {
            std::cout << "La palabra no existe en el diccionario" << std::endl;
            return;
        }
    }
    std::cout << "La palabra tiene un puntaje de puntaje:" << puntaje << std::endl;
}
void comandoIniciarArbol(std::string valor)
{
    std::cout << "comando iniciar_arbol correcto" << std::endl;
    if (valor.compare(" ") == 0 || valor.compare("") == 0)
    {
        std::cout << "Error numero de parametros insuficiente, por favor llame la funcion y seguidamente un archivo de texto " << std::endl;
    }
    return;
}
void comandoIniciarArbolInverso(std::string valor)
{
    std::cout << "comando iniciar_arbol_inverso correcto" << std::endl;
    if (valor.compare(" ") == 0 || valor.compare("") == 0)
    {
        std::cout << "Error numero de parametros insuficiente, por favor llame la funcion y seguidamente un archivo de texto " << std::endl;
    }
    return;
}
void comandoPalabrasPorPrefijo(std::string valor)
{
    std::cout << "comando palabras_por_prefijo correcto" << std::endl;
    if (valor.compare(" ") == 0 || valor.compare("") == 0)
    {
        std::cout << "Error numero de parametros insuficiente, por favor llame la funcion y seguidamente prefijo " << std::endl;
    }
    return;
}
void comandoPalabrasPorSufijo(std::string valor)
{
    std::cout << "comando palabras_por_sufijo correcto" << std::endl;
    if (valor.compare(" ") == 0 || valor.compare("") == 0)
    {
        std::cout << "Error numero de parametros insuficiente, por favor llame la funcion y seguidamente sufijo " << std::endl;
    }
    return;
}
void comandoPosiblesPalabras(std::string valor)
{
    std::cout << "comando palabras_por_sufijo correcto" << std::endl;
    if (valor.compare(" ") == 0 || valor.compare("") == 0)
    {
        std::cout << "Error numero de parametros insuficiente, por favor llame la funcion y seguidamente sufijo " << std::endl;
    }
    return;
}
void comandoGrafoDePalabras(std::string valor)
{
    std::cout << "comando posibles_palabras correcto" << std::endl;
    if (valor.compare(" ") == 0 || valor.compare("") == 0)
    {
        std::cout << "Error numero de parametros insuficiente, por favor llame la funcion y seguidamente una cadena de letras " << std::endl;
    }
    return;
}

int main(int argc, char *argv[])
{
    int loop = 0;
    std::deque<Diccionario> listaDiccionarios;

    while (loop == 0)
    {

        std::string funcion_valor, funcion = "", valor = "";
        std::cout << "$ ";
        std::getline(std::cin, funcion_valor);
        int contador = 0;
        for (auto x : funcion_valor)
        {
            if (x == ' ')
            {
                contador++;
                exit;
            }
            if (contador == 0)
            {
                funcion = funcion + x;
            }
            else if (contador != 0)
            {
                if (!std::isspace(x))
                {
                    valor = valor + x;
                }
            }
        }

        if (funcion.compare("ayuda") == 0)
        {
            if (valor.empty())
            {
                comandoAyuda();
            }
            else
            {
                comandoAyudaEspecifico(valor);
            }
        }
        else if (funcion.compare("inicializar") == 0)
        {
            comandoInicializar(valor, listaDiccionarios);
        }
        else if (funcion.compare("iniciar_inverso") == 0)
        {
            comandoInicializarInverso(valor, listaDiccionarios);
        }
        else if (funcion.compare("puntaje") == 0)
        {
            comandoPuntaje(valor, listaDiccionarios);
        }
        else if (funcion.compare("salir") == 0)
        {
            std::cout << "comando salir correcto" << std::endl;
            loop = 1;
        }
        else if (funcion.compare("iniciar_arbol") == 0)
        {
            comandoIniciarArbol(valor);
        }
        else if (funcion.compare("iniciar_arbol_inverso") == 0)
        {
            comandoIniciarArbolInverso(valor);
        }
        else if (funcion.compare("palabras_por_prefijo") == 0)
        {
            comandoPalabrasPorPrefijo(valor);
        }
        else if (funcion.compare("palabras_por_sufijo") == 0)
        {
            comandoPalabrasPorSufijo(valor);
        }
        else if (funcion.compare("grafo_de_palabras") == 0)
        {
            comandoGrafoDePalabras(valor);
        }
        else if (funcion.compare("posibles_palabras") == 0)
        {
            comandoPosiblesPalabras(valor);
        }
        else
        {
            std::cout << "comando invalido, use el comando ayuda para ver los comandos" << std::endl;
        }
    }
}