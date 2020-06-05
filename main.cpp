#include <iostream>
#include <chrono>
#include <climits>
#include "funciones.h"
#include "db.h"


using namespace std;

/**
 * Ejemplo 
 * @param argc cantidad de argumentos
 * @param argv argumentos
 * @return El código de salida del programa
 */
int main(int argc, char** argv) {

<<<<<<< HEAD
    std::vector<int> arreglo;

    for (int largo = 1; largo < (INT_MAX / 2); largo *= 1000) {
=======
    int i = 0;

    for (int largo = 1; largo < (INT_MAX / 2); largo *= 100) {
>>>>>>> f4252e56f5678722957b926612afc26c905bc1c1
        auto inicio = chrono::steady_clock::now();
        arreglo = generarVector(100000);
        //quicksort
        auto termino = chrono::steady_clock::now();
        auto duracion = chrono::duration_cast<chrono::nanoseconds>(termino - inicio).count();
        std::cout << std::endl << "Generacion de " << largo << "  demoró (" << duracion << " ns) " << std::endl;
        std::string sql;
        sql = "INSERT INTO ejecuciones (usuario_fk, algoritmo_fk, cantidad, duracion) VALUES ('1','1','" + std::to_string(largo) + "','" + std::to_string(duracion) + "')";
        // std::string algoritmo;
        // algoritmo = "INSERT INTO algoritmos (nombre, descripcion) VALUES ('quicksort', 'ordenamiento algoritmo rapido');";
        PGconn* conexion = conectarDb((char *) "sebastian.cl", 5432, (char *) "aadb", (char *) "bravo", (char *) "grupo02");
        PGresult* resultado = consultarDb(conexion, (char *) sql.c_str());
        liberarResultadoDb(resultado);
        desconectarDb(conexion);
    }

    quickSort(arreglo, 0, arreglo.size());
    imprimirVector(arreglo);

     /**
     * Despliegue de participantes
     */
    participantes();


   
    return EXIT_SUCCESS;
}


