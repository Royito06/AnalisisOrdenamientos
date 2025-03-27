
#define ALGORITMOS_ORDENAMIENTO_H_INCLUDED

#include <vector>

/**
 * Ordena un arreglo usando el método de inserción.
 *
 * @param arreglo Arreglo de enteros a ordenar (se modifica directamente)
 * @param n Tamaño del arreglo
 */
void ordenamientoPorInsercion(std::vector<int>& arr);

//**************************************************************************

/**
 * Ordena un arreglo usando el método de burbuja clásico.
 *
 * @param arreglo Arreglo de enteros a ordenar (se modifica directamente)
 * @param n Tamaño del arreglo
 */
void ordenamientoBurbuja(std::vector<int>& arr);

//**************************************************************************

/**
 * Versión optimizada del ordenamiento burbuja.
 *
 * @param arreglo Arreglo de enteros a ordenar (se modifica directamente)
 * @param n Tamaño del arreglo
 */
void ordenamientoBurbujaOptimizado(std::vector<int>& arr);

//**************************************************************************

/**
 * Ordena un arreglo usando el método de selección.
 *
 * @param arreglo Arreglo de enteros a ordenar (se modifica directamente)
 * @param n Tamaño del arreglo
 */
void ordenamientoPorSeleccion(std::vector<int>& arr);

//**************************************************************************

/**
 * Función auxiliar para el Merge Sort.
 *
 * @param arreglo Arreglo principal
 * @param left Índice izquierdo del subarreglo
 * @param mid Índice medio del subarreglo
 * @param right Índice derecho del subarreglo
 */
void merge(std::vector<int>& arr, int left, int mid, int right);

//**************************************************************************

/**
 * Ordena un arreglo usando el método Merge Sort.
 *
 * @param arreglo Arreglo de enteros a ordenar (se modifica directamente)
 * @param left Índice inicial del subarreglo
 * @param right Índice final del subarreglo
 */
void mergeSort(std::vector<int>& arr, int left, int right);

//**************************************************************************

/**
 * Función auxiliar para el Quick Sort.
 *
 * @param arreglo Arreglo a particionar
 * @param low Índice inferior del subarreglo
 * @param high Índice superior del subarreglo (usado como pivote)
 * @return Índice de la posición final del pivote
 */
int partition(std::vector<int>& arr, int low, int high);

//**************************************************************************

/**
 * Ordena un arreglo usando el método Quick Sort.
 *
 * @param arreglo Arreglo de enteros a ordenar (se modifica directamente)
 * @param low Índice inicial del subarreglo
 * @param high Índice final del subarreglo
 */
void quickSort(std::vector<int>& arr, int low, int high);

//**************************************************************************

/**
 * Función auxiliar para el Heap Sort.
 *
 * @param arreglo Arreglo a ordenar
 * @param n Tamaño del heap
 * @param i Índice raíz del subárbol
 */
void heapify(std::vector<int>& arr, int n, int i);

//**************************************************************************

/**
 * Ordena un arreglo usando el método Heap Sort.
 *
 * @param arreglo Arreglo de enteros a ordenar (se modifica directamente)
 * @param n Tamaño del arreglo
 */
void heapSort(std::vector<int>& arr);

//**************************************************************************

/**
 * Ordena un arreglo usando el método Shell Sort.
 *
 * @param arreglo Arreglo de enteros a ordenar (se modifica directamente)
 * @param n Tamaño del arreglo
 */
void shellSort(std::vector<int>& arr);

#endif // ALGORITMOS_ORDENAMIENTO_H_INCLUDED
