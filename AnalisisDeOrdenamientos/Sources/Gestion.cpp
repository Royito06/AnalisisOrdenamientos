#include <vector>
#include <chrono>
#include <fstream>
#include <string>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include "../headers/Ordenamientos.h"
#include "../headers/Generador.h"

using namespace std::chrono;

void ejecutarPruebas(const std::string& archivoCSV = "resultados.csv") {
    std::ofstream archivo(archivoCSV);

    //constantes
    const int INCREMENTO_TAMANO = 10;
    const int TAMANO_INICIAL = 10;
    const int MAX_TAMANO = 1000;
    const int NUM_PRUEBAS = 10;

    //lista de algoritmos a probar
    std::vector<std::pair<std::string, void(*)(std::vector<int>&)>> algoritmos = {
        {"Insercion", ordenamientoPorInsercion},
        {"Burbuja", ordenamientoBurbuja},
        {"BurbujaOpt", ordenamientoBurbujaOptimizado},
        {"Seleccion", ordenamientoPorSeleccion},
        {"MergeSort", [](std::vector<int>& v){ mergeSort(v, 0, v.size()-1); }},
        {"QuickSort", [](std::vector<int>& v){ quickSort(v, 0, v.size()-1); }},
        {"HeapSort", heapSort},
        {"ShellSort", shellSort}
    };

    // Cabecera CSV (algoritmos como columnas)
    archivo << "Tama�o";
    for (const auto& alg : algoritmos) {
        archivo << "," << alg.first;
    }
    archivo << "\n";

    // Para cada tamaño,esto son las filas
    for (int tamano = TAMANO_INICIAL; tamano <= MAX_TAMANO; tamano += INCREMENTO_TAMANO) {
        archivo << tamano;

        // Para cada algoritmo, estas son las columnas
        for (const auto& alg : algoritmos) {
            long long tiempo_total = 0;
            bool correcto = true;

            // Repeticiones (NUM_PRUEBAS)
            for (int prueba = 0; prueba < NUM_PRUEBAS; ++prueba) {
                auto arreglo = generarArregloAleatorio(tamano);
                auto copia = arreglo;

                auto inicio = high_resolution_clock::now();
                alg.second(copia);
                auto fin = high_resolution_clock::now();

                tiempo_total += duration_cast<microseconds>(fin - inicio).count();
                correcto &= is_sorted(copia.begin(), copia.end());
            }

            // Tiempo promedio
            archivo << "," << std::fixed << std::setprecision(2)
                   << static_cast<double>(tiempo_total) / NUM_PRUEBAS;


        }

        archivo << "\n";
        std::cout << "Completado tama\244o: " << tamano << std::endl;
    }

    archivo.close();
}
