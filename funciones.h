#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <vector>
#include <random>

/**
 * 
 * @return un número entero positivo aleatoreo
 */
int aleatoreo();

/**
 * 
 * @param inferior Límite inferio
 * @param superior Límite superior
 * @return un número aleatore entre el rango
 */
int aleatoreo(int inferior, int superior);

/**
 * 
 * @param largo Tamaño del arreglo de entrada
 * @return un vector con números aleatereo
 */
std::vector<int> generarVector(int largo);

/**
 * Imprime en la salida estándar un vector
 * @param arreglo Vector a mostrar
 */
void imprimirVector(std::vector<int> arreglo);

/**
 * Función que muestra los participantes del grupo
 */
void participantes();

/**
 * Quicksort en c extraido de https://stackoverflow.com/questions/22504837/how-to-implement-quick-sort-algorithm-in-c
 */
void quickSort(std::vector<int>& a, int p,int q);
int partition(std::vector<int>& a, int p,int q);


#endif /* FUNCIONES_H */

