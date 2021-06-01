// proyecto de estructuras
// Diego Alejandro Cardozo Rojas, Brayan Estiben Giraldo Lopoez, David Alejandro Antolinez Socha

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "utilidades.h"
#include "tadMaestro.h"

std::string archivoArbol = "";
std::string archivoArbolInv = "";

std::vector<std::vector<GestorPalabras>> llenadoArregloComparacionPalabras(std::vector<std::string> listaPalabras)
{
    std::vector<std::vector<GestorPalabras>> arreglo;
    std::vector<GestorPalabras> arregloPequeno;
    GestorPalabras aux;
    bool encontrado = false;
    for (int i = 0; i < listaPalabras.size(); i++)
    {
        if (arreglo.empty())
        {
            aux.palabras = listaPalabras[i];
            aux.tamano = listaPalabras[i].length();
            arregloPequeno.push_back(aux);
            arreglo.push_back(arregloPequeno);
            arregloPequeno.clear();
        }
        else
        {
            encontrado = false;
            for (int j = 0; j < arreglo.size(); j++)
            {
                if (arreglo[j][0].tamano == listaPalabras[i].length())
                {
                    aux.palabras = listaPalabras[i];
                    aux.tamano = listaPalabras[i].length();
                    arreglo[j].push_back(aux);
                    encontrado = true;
                }
            }
            if (!encontrado)
            {
                aux.palabras = listaPalabras[i];
                aux.tamano = listaPalabras[i].length();
                arregloPequeno.push_back(aux);
                arreglo.push_back(arregloPequeno);
                arregloPequeno.clear();
            }
        }
    }
    return arreglo;
}

bool verificarPalabra(std::string linea)
{
    bool verificacionPalabra = true;
    for (int i = 0; i < linea.size(); i++)
    {
        if (!isalpha(linea[i]))
        {
            return false;
        }
    }
    return verificacionPalabra;
}

void comandoInicializar(std::string valor, std::vector<Diccionario> &listaDiccionarios)
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
    std::vector<std::string> palabrasAux;
    int contador = 0;

    std::vector<Diccionario>::iterator itDiccionario;

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

void comandoInicializarInverso(std::string valor, std::vector<Diccionario> &listaDiccionarios)
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
    std::vector<std::string> palabrasAux;

    std::vector<Diccionario>::iterator itDiccionario;

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
    }
    for (int i = 0; i < pun2.size(); i++)
    {
        if (pun2[i] == letra)
        {
            return 2;
        }
    }

    for (int i = 0; i < pun3.size(); i++)
    {
        if (pun3[i] == letra)
        {
            return 3;
        }
    }
    for (int i = 0; i < pun4.size(); i++)
    {
        if (pun4[i] == letra)
        {
            return 4;
        }
    }
    for (int i = 0; i < pun8.size(); i++)
    {
        if (pun8[i] == letra)
        {
            return 8;
        }
    }
    for (int i = 0; i < pun10.size(); i++)
    {
        if (pun10[i] == letra)
        {
            return 10;
        }
    }
    return -1;
}

void comandoPuntaje(std::string valor, std::vector<Diccionario> &listaDiccionarios)
{
    int puntaje = 0;
    std::vector<Diccionario>::iterator itDiccionario;
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

void comandoIniciarArbol(std::string valor, Tree<char> &arbol, std::vector<std::string> &arbolesNormales)
{
    if (valor.compare(" ") == 0 || valor.compare("") == 0)
    {
        std::cout << "Error numero de parametros insuficiente, por favor llame la funcion y seguidamente un archivo de texto " << std::endl;
    }
    std::vector<std::string>::iterator it;
    it = find(arbolesNormales.begin(), arbolesNormales.end(), valor);
    if (it != arbolesNormales.end())
    {
        std::cout << "El Arbol del diccionario ya ha sido inicializado " << std::endl;
        return;
    }
    std::ifstream archivo;
    std::string linea, nombreArchivo = valor;
    archivoArbol = nombreArchivo;
    archivo.open(nombreArchivo);
    bool verificacionPalabra = true;
    if (!archivo.is_open())
    {
        std::cout << "El archivo " << valor << " no existe o no puede ser leido " << std::endl;
        return;
    }
    if (archivo.is_open())
    {
        while (std::getline(archivo, linea))
        {
            verificacionPalabra = verificarPalabra(linea);
            if (verificacionPalabra)
            {
                for (int i = 0; i < linea.length(); i++)
                {
                    linea[i] = tolower(linea[i]);
                }
                arbol.insertar1(linea);
            }
        }
        archivo.close();
    }
    arbolesNormales.push_back(valor);
    std::cout << "El arbol de ha inicializado correctamente" << std::endl;
    return;
}
void comandoIniciarArbolInverso(std::string valor, Tree<char> &arbolInv, std::vector<std::string> &arbolesInversos)
{
    if (valor.compare(" ") == 0 || valor.compare("") == 0)
    {
        std::cout << "Error numero de parametros insuficiente, por favor llame la funcion y seguidamente un archivo de texto " << std::endl;
    }

    std::vector<std::string>::iterator it;
    it = find(arbolesInversos.begin(), arbolesInversos.end(), valor);

    if (it != arbolesInversos.end())
    {
        std::cout << "El Arbol del diccionario ya ha sido inicializado " << std::endl;
        return;
    }

    std::ifstream archivo;
    std::string linea, nombreArchivo = valor;
    archivoArbolInv = nombreArchivo;
    archivo.open(nombreArchivo);
    bool verificacionPalabra = true;

    if (!archivo.is_open())
    {
        std::cout << "El archivo " << valor << " no existe o no puede ser leido " << std::endl;
        return;
    }

    if (archivo.is_open())
    {
        while (std::getline(archivo, linea))
        {
            verificacionPalabra = verificarPalabra(linea);
            if (verificacionPalabra)
            {
                for (int i = 0; i < linea.length(); i++)
                {
                    linea[i] = tolower(linea[i]);
                }
                std::reverse(linea.begin(), linea.end());
                arbolInv.insertar1(linea);
            }
        }
        archivo.close();
    }
    arbolesInversos.push_back(valor);
    std::cout << "El arbol de ha inicializado correctamente" << std::endl;
    return;
}
void comandoPalabrasPorPrefijo(std::string valor, Tree<char> &arbol)
{
    if (valor.compare(" ") == 0 || valor.compare("") == 0)
    {
        std::cout << "Error numero de parametros insuficiente, por favor llame la funcion y seguidamente prefijo " << std::endl;
    }

    std::string prefijo = valor;
    arbol.prefijo(prefijo, archivoArbol);

    return;
}
void comandoPalabrasPorSufijo(std::string valor, Tree<char> &arbolInv)
{
    if (valor.compare(" ") == 0 || valor.compare("") == 0)
    {
        std::cout << "Error numero de parametros insuficiente, por favor llame la funcion y seguidamente sufijo " << std::endl;
    }

    std::string sufijo = valor;
    arbolInv.sufijo(sufijo, archivoArbolInv);

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
void comandoGrafoDePalabras(std::string valor, std::vector<Grafo> &grafos, Diccionario diccionario)
{
    if (valor.compare(" ") == 0 || valor.compare("") == 0)
    {
        std::cout << "Error numero de parametros insuficiente, por favor llame la funcion y seguidamente una cadena de letras " << std::endl;
    }
    int comparacionValidacion = 0;
    std::vector<std::string> listaPalabras = diccionario.obtenerPalabras();
    std::vector<std::string> auxPalabras;
    std::vector<std::vector<GestorPalabras>> arregloTamanoPalabras = llenadoArregloComparacionPalabras(listaPalabras);
    Grafo grafo;
    /*
    for (int i = 0; i < listaPalabras.size(); i++)
    {
        std::cout << listaPalabras[i] << std::endl;
    }
    std::cout << "-------------------------" << std::endl;
    for (int i = 0; i < arregloTamanoPalabras.size(); i++)
    {
        std::cout << "imprimiendo palabras de tamano" << arregloTamanoPalabras[i][0].tamano << std::endl;
        for (int j = 0; j < arregloTamanoPalabras[i].size(); j++)
        {
            std::cout << arregloTamanoPalabras[i][j].palabras << std::endl;
        }
    }
    */
    for (int x = 0; x < arregloTamanoPalabras.size(); x++)
    {
        /* code */

        std::cout << "insertando los datos" << std::endl;
        grafo.iniciarMatrix(arregloTamanoPalabras[x].size());
        std::vector<std::string> palabrasGrafo;

        for (int v = 0; v < arregloTamanoPalabras[x].size(); v++)
        {
            palabrasGrafo.push_back(arregloTamanoPalabras[x][v].palabras);
        }

        auxPalabras = palabrasGrafo;

        grafo.insertarVertice(palabrasGrafo);
        std::cout << "termino la insertcion de los datos " << std::endl;

        for (int i = 0; i < palabrasGrafo.size(); i++)
        {
            for (int j = 0; j < auxPalabras.size(); j++)
            {
                comparacionValidacion = compararPalabra(palabrasGrafo[i], auxPalabras[j]);
                if (comparacionValidacion != -1)
                {
                    //std::cout << " hay conexion entre " << listaPalabras[i] << " y " << arregloTamanoPalabras[j][k].palabras << std::endl;
                    grafo.insetarArista(palabrasGrafo[i], auxPalabras[j], comparacionValidacion);
                }
            }

            /*
        for (int j = 0; j < arregloTamanoPalabras.size(); j++)
        {
            if (arregloTamanoPalabras[j][0].tamano == palabrasGrafo[i].length())
            {
                for (int k = 0; k < arregloTamanoPalabras[j].size(); k++)
                {
                    comparacionValidacion = compararPalabra(palabrasGrafo[i], arregloTamanoPalabras[j][k].palabras);
                    if (comparacionValidacion != -1)
                    {
                        //std::cout << " hay conexion entre " << listaPalabras[i] << " y " << arregloTamanoPalabras[j][k].palabras << std::endl;
                        grafo.insetarArista(palabrasGrafo[i], arregloTamanoPalabras[j][k].palabras, comparacionValidacion);
                    }
                }
            }
        }
        */
            auxPalabras.erase(auxPalabras.begin());
        }
        std::cout << "termino la insertcion de las aristas del grafo: " << x << std::endl;
        //std::cout << "sus matrix y sus datos son" << std::endl;
        //grafo.imprimirVertices();
        //grafo.imprimirMatrix();
    }
    return;
}

int main(int argc, char *argv[])
{
    int loop = 0;
    TadMaestro maestro;
    std::vector<Diccionario> listaDiccionarios = maestro.obtenerDiccionarios();
    std::vector<std::string> arbolesNormales = maestro.obtenerArbolNormales();
    std::vector<std::string> arbolesInversos = maestro.obtenerArbolInversos();
    std::vector<std::vector<GestorPalabras>> arregloComparacionPalabras;
    std::vector<Grafo> arregloGrafos = maestro.obtenerGrafo();
    Tree<char> arbolInv;
    Tree<char> arbol;
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
            comandoIniciarArbol(valor, arbol, arbolesNormales);
        }
        else if (funcion.compare("iniciar_arbol_inverso") == 0)
        {
            std::system("clear");
            comandoIniciarArbolInverso(valor, arbolInv, arbolesInversos);
        }
        else if (funcion.compare("palabras_por_prefijo") == 0)
        {
            std::system("clear");
            comandoPalabrasPorPrefijo(valor, arbol);
        }
        else if (funcion.compare("palabras_por_sufijo") == 0)
        {
            std::system("clear");
            comandoPalabrasPorSufijo(valor, arbolInv);
        }
        else if (funcion.compare("grafo_de_palabras") == 0)
        {
            std::system("clear");
            comandoGrafoDePalabras(valor, arregloGrafos, listaDiccionarios[0]);
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