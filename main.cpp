// proyecto de estructuras

#include <iostream>

int main(int argc, char *argv[])
{
    std::string variable;
    std::cout << " " << std::endl;
    std::cout << "⠄⠄⠄⠄⠄⢴⡶⣶⣶⣶⡒⣶⣶⣖⠢⡄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄" << std::endl;
    std::cout << "⠄⠄⠄⠄⠄⠄⢠⣿⣋⣿⣿⣉⣿⣿⣯⣧⡰⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄" << std::endl;
    std::cout << "⠄⠄⠄⠄⠄⠄⣿⣿⣹⣿⣿⣏⣿⣿⡗⣿⣿⠁⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄" << std::endl;
    std::cout << "⠄⠄⠄⠄⠄⠄⠟⡛⣉⣭⣭⣭⠌⠛⡻⢿⣿⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄" << std::endl;
    std::cout << "⠄⠄⠄⠄⠄⠄⠄⠄⣤⡌⣿⣷⣯⣭⣿⡆⣈⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄" << std::endl;
    std::cout << "⠄⠄⠄⠄⠄⠄⠄⢻⣿⣿⣿⣿⣿⣿⣿⣷⢛⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄-------------> A Product Of Machete Company" << std::endl;
    std::cout << "⠄⠄⠄⠄⠄⠄⠄⠄⢻⣷⣽⣿⣿⣿⢿⠃⣼⣧⣀⠄⠄⠄⠄⠄⠄⠄⠄⠄" << std::endl;
    std::cout << "⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣛⣻⣿⠟⣀⡜⣻⢿⣿⣿⣶⣤⡀⠄⠄⠄⠄⠄" << std::endl;
    std::cout << "⠄⠄⠄⠄⠄⠄⠄⠄⢠⣤⣀⣨⣥⣾⢟⣧⣿⠸⣿⣿⣿⣿⣿⣤⡀⠄⠄⠄" << std::endl;
    std::cout << "⠄⠄⠄⠄⠄⠄⠄⠄⢟⣫⣯⡻⣋⣵⣟⡼⣛⠴⣫⣭⣽⣿⣷⣭⡻⣦⡀⠄" << std::endl;
    std::cout << "⠄⠄⠄⠄⠄⠄⠄⢰⣿⣿⣿⢏⣽⣿⢋⣾⡟⢺⣿⣿⣿⣿⣿⣿⣷⢹⣷⠄" << std::endl;
    std::cout << "⠄⠄⠄⠄⠄⠄⠄⣿⣿⣿⢣⣿⣿⣿⢸⣿⡇⣾⣿⠏⠉⣿⣿⣿⡇⣿⣿⡆" << std::endl;
    std::cout << "⠄⠄⠄⠄⠄⠄⠄⣿⣿⣿⢸⣿⣿⣿⠸⣿⡇⣿⣿⡆⣼⣿⣿⣿⡇⣿⣿⡇" << std::endl;
    std::cout << "⠇⢀⠄⠄⠄⠄⠄⠘⣿⣿⡘⣿⣿⣷⢀⣿⣷⣿⣿⡿⠿⢿⣿⣿⡇⣩⣿⡇" << std::endl;
    std::cout << "⣿⣿⠃⠄⠄⠄⠄⠄⠄⢻⣷⠙⠛⠋⣿⣿⣿⣿⣿⣷⣶⣿⣿⣿⡇⣿⣿⡇" << std::endl;

    std::string funcion = argv[1];
    if(funcion.compare("ayuda") == 0){
        std::cout << "comandos validos:" << std::endl;
        std::cout << "- inicializar" << std::endl
         << "- iniciar_inverso" << std::endl
         << "- puntaje" << std::endl
         << "- salir" << std::endl
         << "- iniciar_arbol" << std::endl
         << "- iniciar_arbol_inverso" << std::endl
         << "- palabras_por_prefijo" << std::endl
         << "- palabras_por_sufijo" << std::endl
         << "- grafo_de_palabras" << std::endl
         << "- posibles_palabras" << std::endl;
    }
    else if (funcion.compare("inicializar") == 0)
    {
        std::cout << "comando inicializar correcto";
    }
    else if (funcion.compare("iniciar_inverso") == 0)
    {
        std::cout << "comando iniciar_inverso correcto";
    }
    else if (funcion.compare("puntaje") == 0)
    {
        std::cout << "comando puntaje correcto";
    }
    else if (funcion.compare("salir") == 0)
    {
        std::cout << "comando salir correcto" << std::endl;
    }
    else if (funcion.compare("iniciar_arbol") == 0)
    {
        std::cout << "comando iniciar_arbol correcto" << std::endl;
    }
    else if (funcion.compare("iniciar_arbol_inverso") == 0)
    {
        std::cout << "comando iniciar_arbol_inverso correcto" << std::endl;
    }
    else if (funcion.compare("palabras_por_prefijo") == 0)
    {
        std::cout << "comando palabras_por_prefijo correcto" << std::endl;
    }
    else if (funcion.compare("palabras_por_sufijo") == 0)
    {
        std::cout << "comando palabras_por_sufijo correcto" << std::endl;
    }
    else if (funcion.compare("grafo_de_palabras") == 0)
    {
        std::cout << "comando grafo_de_palabras correcto" << std::endl;
    }
    else if (funcion.compare("posibles_palabras") == 0)
    {
        std::cout << "comando posibles_palabras correcto" << std::endl;
    }
    else
    {
        std::cout << "comando invalido, use el comando ayuda para ver los comandos" << std::endl;
    }
}