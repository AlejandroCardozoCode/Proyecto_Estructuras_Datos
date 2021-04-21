// proyecto de estructuras
// Diego Alejandro Cardozo Rojas, Brayan Estiben Giraldo Lopoez, David Alejandro Antolinez Socha

#include <iostream>
#include <fstream>
#include <deque>
#include "diccionario.h"
#include <algorithm>
#include "utilidades.h"
#include "arbol.h"

bool verificarPalabra(std::string linea)
{
    bool verificacionPalabra = true;
    for (int i = 0; i < linea.size(); i++)
    {
        if (!isalpha(linea[i]))
        {
            return false;
            //std::cout << "La palabra " << linea << " contiene caracteres invalidos, no se agregara a el diccionario " << std::endl;
        }
    }
    return verificacionPalabra;
}

void comandoInicializar(std::string valor, std::deque<Diccionario> &listaDiccionarios)
{
    if (valor.compare(" ") == 0 || valor.compare("") == 0)
    {
        std::cout << "Error numero de parametros insuficiente, por favor llame la funcion y seguidamente el arichivo de texto " << std::endl;
    }

    std::string linea, nombreArchivo = valor;
    std::ifstream archivo;
    int lineasArchivo = 0, contadorPalabrasNoValidas = 0;
    bool verificacionPalabra = true;
    Diccionario diccionarioAux;
    std::deque<std::string> palabrasAux;
    int contador = 0;

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
            contador++;
            verificacionPalabra = verificarPalabra(linea);
            if (verificacionPalabra)
            {
                diccionarioAux.insertarPalabra(linea);
            }
            else
            {
                contadorPalabrasNoValidas++;
            }
        }
        diccionarioAux.verificarRepetidas();
        if (contadorPalabrasNoValidas != 0)
        {
            std::cout << "El archivo de texto tenia: " << contadorPalabrasNoValidas << " palabras no validas, estas no se agregaron al diccionario" << std::endl;
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
    if (valor.compare(" ") == 0 || valor.compare("") == 0)

    {
        std::cout << "Error numero de parametros insuficiente, por favor llame la funcion y seguidamente el arichivo de texto " << std::endl;
    }

    std::string linea, nombreArchivo = valor;
    std::ifstream archivo;
    int lineasArchivo = 0, contadorPalabrasNoValidas = 0;
    bool verificacionPalabra = true;
    Diccionario diccionarioAux;
    std::deque<std::string> palabrasAux;

    std::deque<Diccionario>::iterator itDiccionario;

    for (itDiccionario = listaDiccionarios.begin(); itDiccionario != listaDiccionarios.end(); itDiccionario++)
    {
        if (itDiccionario->obtenerNombre() == nombreArchivo + "inv")
        {
            std::cout << "El diccionario inverso ya ha sido inicializado." << std::endl;
            return;
        }
    }

    diccionarioAux.fiajarNombre(nombreArchivo + "inv");
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
            else
            {
                contadorPalabrasNoValidas++;
            }
        }
        diccionarioAux.verificarRepetidas();
        if (contadorPalabrasNoValidas != 0)
        {
            std::cout << "El archivo de texto tenia: " << contadorPalabrasNoValidas << " palabras no validas, estas no se agregaron al diccionario" << std::endl;
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
    bool palabraNormal = false, palabraInversa = false;
    if (valor.compare(" ") == 0 || valor.compare("") == 0)
    {
        std::cout << "Error numero de parametros insuficiente, por favor llame la funcion y seguidamente una palabra " << std::endl;
    }
    if (!verificarPalabra(valor))
    {
        std::cout << "La palabra contiene símbolos inválidos" << std::endl;
        return;
    }
    for (itDiccionario = listaDiccionarios.begin(); itDiccionario != listaDiccionarios.end(); itDiccionario++)
    {
        if (itDiccionario->existePalabraInv(valor))
        {
            palabraInversa = true;
        }
        if (itDiccionario->existePalabra(valor))
        {
            palabraNormal = true;
        }
    }
    if (palabraInversa && palabraNormal)
    {
        for (int i = 0; i < valor.size(); i++)
        {
            puntaje += puntos(valor[i]);
        }
    }
    else if (!palabraNormal || !palabraInversa)
    {
        std::cout << "La palabra no existe en el diccionario normal o el inverso" << std::endl;
        return;
    }
    std::cout << "La palabra tiene un puntaje de puntaje:" << puntaje << std::endl;
}
void comandoIniciarArbol(std::string valor)
{
    if (valor.compare(" ") == 0 || valor.compare("") == 0)
    {
        std::cout << "Error numero de parametros insuficiente, por favor llame la funcion y seguidamente un archivo de texto " << std::endl;
    }
    std::ifstream archivo;
    std::string linea, nombreArchivo = valor;
    Tree<char> arbol;
    archivo.open(nombreArchivo);
    if (archivo.is_open())
    {
        while (std::getline(archivo, linea))
        {
            std::cout << "nueva iteracion" << std::endl;
            for (int i = 0; i < linea.length(); i++)
            {
                linea[i] = tolower(linea[i]);
            }
            arbol.insertar1(linea);
        }
        archivo.close();
    }
}
void comandoIniciarArbolInverso(std::string valor)
{
    if (valor.compare(" ") == 0 || valor.compare("") == 0)
    {
        std::cout << "Error numero de parametros insuficiente, por favor llame la funcion y seguidamente un archivo de texto " << std::endl;
    }
    std::ifstream archivo;
    std::string linea, nombreArchivo = valor;
    Tree<char> arbol;
    archivo.open(nombreArchivo);
    if (archivo.is_open())
    {
        while (std::getline(archivo, linea))
        {
            std::cout << "nueva iteracion" << std::endl;
            for (int i = 0; i < linea.length(); i++)
            {
                linea[i] = tolower(linea[i]);
            }
            std::reverse(linea.begin(), linea.end());
            arbol.insertar1(linea);
        }
        archivo.close();
    }
    return;
}
void comandoPalabrasPorPrefijo(std::string valor)
{
    if (valor.compare(" ") == 0 || valor.compare("") == 0)
    {
        std::cout << "Error numero de parametros insuficiente, por favor llame la funcion y seguidamente prefijo " << std::endl;
    }
    return;
}
void comandoPalabrasPorSufijo(std::string valor)
{
    if (valor.compare(" ") == 0 || valor.compare("") == 0)
    {
        std::cout << "Error numero de parametros insuficiente, por favor llame la funcion y seguidamente sufijo " << std::endl;
    }
    return;
}
void comandoPosiblesPalabras(std::string valor)
{
    if (valor.compare(" ") == 0 || valor.compare("") == 0)
    {
        std::cout << "Error numero de parametros insuficiente, por favor llame la funcion y seguidamente sufijo " << std::endl;
    }
    return;
}
void comandoGrafoDePalabras(std::string valor)
{
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

    std::system("clear");
    while (loop == 0)
    {

        std::string funcion_valor, funcion = "", valor = "";
        std::cout << "$: ";
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
            std::system("clear");
            if (valor.empty())
            {
                impresionAyuda();
            }
            else
            {
                impresionAyudaEspecifico(valor);
            }
        }
        else if (funcion.compare("inicializar") == 0)
        {
            std::system("clear");
            comandoInicializar(valor, listaDiccionarios);
        }
        else if (funcion.compare("iniciar_inverso") == 0)
        {
            std::system("clear");
            comandoInicializarInverso(valor, listaDiccionarios);
        }
        else if (funcion.compare("puntaje") == 0)
        {
            std::system("clear");
            comandoPuntaje(valor, listaDiccionarios);
        }
        else if (funcion.compare("salir") == 0)
        {
            std::system("clear");
            std::cout << "Saliendo del sistema..." << std::endl;
            loop = 1;
        }
        else if (funcion.compare("iniciar_arbol") == 0)
        {
            std::system("clear");
            comandoIniciarArbol(valor);
        }
        else if (funcion.compare("iniciar_arbol_inverso") == 0)
        {
            std::system("clear");
            comandoIniciarArbolInverso(valor);
        }
        else if (funcion.compare("palabras_por_prefijo") == 0)
        {
            std::system("clear");
            comandoPalabrasPorPrefijo(valor);
        }
        else if (funcion.compare("palabras_por_sufijo") == 0)
        {
            std::system("clear");
            comandoPalabrasPorSufijo(valor);
        }
        else if (funcion.compare("grafo_de_palabras") == 0)
        {
            std::system("clear");
            comandoGrafoDePalabras(valor);
        }
        else if (funcion.compare("posibles_palabras") == 0)
        {
            std::system("clear");
            comandoPosiblesPalabras(valor);
        }
        else
        {
            std::system("clear");
            std::cout << "comando invalido, use el comando <ayuda> para ver los comandos" << std::endl;
        }
    }
}