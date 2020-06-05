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

    int i = 0;

    for (int largo = 1; largo < (INT_MAX / 2); largo *= 100) {
        auto inicio = chrono::steady_clock::now();
        std::vector<int> arreglo = generarVector(largo);
        //quicksort
        quickSort(arreglo, 0, largo);
        auto termino = chrono::steady_clock::now();
        auto duracion = chrono::duration_cast<chrono::nanoseconds>(termino - inicio).count();
        std::cout << std::endl << "Generacion de " << largo << "  demoró (" << duracion << " ns) " << arreglo.at(i) << std::endl;
        i++;
        cout << i << endl;
        std::string sql;
        sql = "INSERT INTO ejecuciones (usuario_fk, algoritmo_fk, cantidad, duracion) VALUES ('1','1','" + std::to_string(largo) + "','" + std::to_string(duracion) + "')";
        // std::string algoritmo;
        // algoritmo = "INSERT INTO algoritmos (nombre, descripcion) VALUES ('quicksort', 'ordenamiento algoritmo rapido');";
        PGconn* conexion = conectarDb((char *) "sebastian.cl", 5432, (char *) "aadb", (char *) "bravo", (char *) "grupo02");
        PGresult* resultado = consultarDb(conexion, (char *) sql.c_str());
        liberarResultadoDb(resultado);

        desconectarDb(conexion);

    }

    
    


    /**
     * Despliegue de participantes
     */
    participantes();
    return EXIT_SUCCESS;
}


