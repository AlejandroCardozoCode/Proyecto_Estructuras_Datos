#include "utilidades.h"

void impresionAyuda()
{
    std::cout << "comandos validos:" << std::endl
              << "- inicializar" << std::endl
              << "- iniciar_inverso" << std::endl
              << "- puntaje" << std::endl
              << "- salir" << std::endl
              << "- iniciar_arbol" << std::endl
              << "- iniciar_arbol_inverso" << std::endl
              << "- palabras_por_prefijo" << std::endl
              << "- palabras_por_sufijo" << std::endl
              << "- grafo_de_palabras" << std::endl
              << "- posibles_palabras" << std::endl
              << "-------------------------------------------------------------------" << std::endl
              << "Para tener informacion sobre un comando utilice $: ayuda <comando> " << std::endl
              << "-------------------------------------------------------------------" << std::endl;

    return;
}
void impresionAyudaEspecifico(std::string valor)
{
    if (valor.compare("inicializar") == 0)
    {
        std::cout << "- inicializar: llame la funcion y seguidamente el archivo de texto" << std::endl;
    }
    else if (valor.compare("iniciar_inverso") == 0)
    {
        std::cout <<"- iniciar_inverso: llame la funcion y seguidamente el archivo de texto" << std::endl;
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
    return ;
}
