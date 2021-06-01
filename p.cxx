#include <iostream>
#include <list>
#include <deque>

int compararPalabra(std::string palabra1, std::string palabra2)
{
    int contador = 0, posiscionLetraDif = 0;
    if(palabra1.length() != palabra2.length())
    {
        return -1;
    }

    for (int i = 0; i < palabra1.length(); i++)
    {
        if(palabra1[i] == palabra2[i])
        {
            contador ++;
        }
        else
        {
            posiscionLetraDif = i;
        }
    }

    if(contador == palabra1.length() - 1)
    {
        return posiscionLetraDif;
    }
    else
    {
        return -1;
    }
    
}

int main ()
{
    int matriz[0][0];

    matriz = new int [10][10];
    
    return 0;
}