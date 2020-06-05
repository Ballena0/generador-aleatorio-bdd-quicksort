#include <random>
#include <vector>

#include "funciones.h"

int aleatoreo() {
    return aleatoreo(0, 2000000);
}

int aleatoreo(int inferior, int superior) {
    std::random_device dispositivo;

    std::uniform_int_distribution<int> distribucion(inferior, superior);

    return distribucion(dispositivo);
}

std::vector<int> generarVector(int largo) {
    std::vector<int> arreglo;
    for (int i = 0; i < largo; i++) {
        int numero = aleatoreo();
        arreglo.push_back(numero);
    }
    return arreglo;
}

void imprimirVector(std::vector<int> arreglo) {
    std::cout << std::endl << "=== Vector ===" << std::endl;
    for (long unsigned int i = 0; i < arreglo.size(); i++) {
        std::cout << "vector[" << i << "] = " << arreglo.at(i) << std::endl;
    }
}

void participantes() {
    std::cout << std::endl << "=== Ejemplo de Analisis ===" << std::endl;
    std::cout << std::endl << "Sebastián Albornoz M" << std::endl; // Reemplazar por su nombre
    std::cout << std::endl << "Sebastián Santelices G" << std::endl; // Reemplazar por su nombre
    std::cout << std::endl << "Jorge Vergudo Ch" << std::endl; // Reemplazar por su nombre
}


void quickSort(std::vector<int>& a, int p,int q)
{
    int r;
    if(p<q)
    {
        r=partition(a, p,q);
        quickSort(a,p,r);  
        quickSort(a,r+1,q);
    }
}


int partition(std::vector<int>& a, int p,int q)
{
    int x= a[p];
    int i=p;
    int j;

    for(j=p+1; j<q; j++)
    {
        if(a[j]<=x)
        {
            i=i+1;
            std::swap(a[i],a[j]);
        }

    }

    std::swap(a[i],a[p]);
    return i;
}
