// proyecto de estructuras
// Diego Alejandro Cardozo Rojas, Brayan Estiben Giraldo Lopoez, David Alejandro Antolinez Socha

#include <iostream>
#include <fstream>
#include <deque>
#include <algorithm>
#include "arbol.h"
void test(std::string &f, int b)
{
    if( b == 1)
    {
        f = f + 'f';
        test(f, 0);
    }
    std::cout << f << std::endl;
}
int main(int argc, char *argv[])
{
    char f = '0';
    std::cout << f << std::endl;
}