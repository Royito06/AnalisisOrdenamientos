#ifndef GENERADOR_H_INCLUDED
#define GENERADOR_H_INCLUDED
#include <vector>


/**
 * Genera un vector de enteros aleatorios.
 * @param tamano Cantidad de elementos a generar
 * @param max_valor Valor máximo permitido (por defecto 1000)
 * @return Vector con valores aleatorios
 */
std::vector<int> generarArregloAleatorio(int tamano, int max_valor = 10000);

#endif // GENERADOR_H_INCLUDED
