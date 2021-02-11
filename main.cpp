// proyecto de estructuras
// Diego Alejandro Cardozo Rojas, Brayan Estiben Giraldo Lopoez, David Alejandro Antolinez Socha

#include <iostream>

int main(int argc, char *argv[])
{
    int loop = 0;
    while (loop == 0)
    {

        std::string funcion_valor, funcion = "", valor = "";
        std::cout<<"$";
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
                valor = valor + x;
            }
        }

        if (funcion.compare("ayuda") == 0)
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
        }
        else if (funcion.compare("inicializar") == 0)
        {
            std::cout << "comando inicializar correcto" << std::endl;
            if (valor.compare(" ") == 0 || valor.compare("") == 0)
            {
                std::cout << "Error numero de parametros insuficiente, por favor llame la funcion y seguidamente el arichivo de texto " << std::endl;
            }
        }
        else if (funcion.compare("iniciar_inverso") == 0)
        {
            std::cout << "comando iniciar_inverso correcto" << std::endl;
            if (valor.compare(" ") == 0 || valor.compare("") == 0)

            {
                std::cout << "Error numero de parametros insuficiente, por favor llame la funcion y seguidamente el arichivo de texto " << std::endl;
            }
        }
        else if (funcion.compare("puntaje") == 0)
        {
            std::cout << "comando puntaje correcto" << std::endl;
            if (valor.compare(" ") == 0 || valor.compare("") == 0)
            {
                std::cout << "Error numero de parametros insuficiente, por favor llame la funcion y seguidamente una palabra " << std::endl;
            }
        }
        else if (funcion.compare("salir") == 0)
        {
            std::cout << "comando salir correcto" << std::endl;
            loop = 1;
        }
        else if (funcion.compare("iniciar_arbol") == 0)
        {
            std::cout << "comando iniciar_arbol correcto" << std::endl;
            if (valor.compare(" ") == 0 || valor.compare("") == 0)
            {
                std::cout << "Error numero de parametros insuficiente, por favor llame la funcion y seguidamente un archivo de texto " << std::endl;
            }
        }
        else if (funcion.compare("iniciar_arbol_inverso") == 0)
        {
            std::cout << "comando iniciar_arbol_inverso correcto" << std::endl;
            if (valor.compare(" ") == 0 || valor.compare("") == 0)
            {
                std::cout << "Error numero de parametros insuficiente, por favor llame la funcion y seguidamente un archivo de texto " << std::endl;
            }
        }
        else if (funcion.compare("palabras_por_prefijo") == 0)
        {
            std::cout << "comando palabras_por_prefijo correcto" << std::endl;
            if (valor.compare(" ") == 0 || valor.compare("") == 0)
            {
                std::cout << "Error numero de parametros insuficiente, por favor llame la funcion y seguidamente prefijo " << std::endl;
            }
        }
        else if (funcion.compare("palabras_por_sufijo") == 0)
        {
            std::cout << "comando palabras_por_sufijo correcto" << std::endl;
            if (valor.compare(" ") == 0 || valor.compare("") == 0)
            {
                std::cout << "Error numero de parametros insuficiente, por favor llame la funcion y seguidamente sufijo " << std::endl;
            }
        }
        else if (funcion.compare("grafo_de_palabras") == 0)
        {
            std::cout << "comando grafo_de_palabras correcto" << std::endl;
        }
        else if (funcion.compare("posibles_palabras") == 0)
        {
            std::cout << "comando posibles_palabras correcto" << std::endl;
            if (valor.compare(" ") == 0 || valor.compare("") == 0)
            {
                std::cout << "Error numero de parametros insuficiente, por favor llame la funcion y seguidamente una cadena de letras " << std::endl;
            }
        }
        else
        {
            std::cout << "comando invalido, use el comando ayuda para ver los comandos" << std::endl;
        }
    }
}