    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <chrono>
    #include <random>
    #include <fstream>
    #include <string>

    #include "../headers/Ordenamientos.h"
    #include "../headers/Gestion.h"


    using namespace std;


    void ordenamientoPorInsercion(vector<int>& arr) {
        for (size_t i = 1; i < arr.size(); ++i) {
            int clave = arr[i];
            size_t j = i;

            while (j > 0 && arr[j-1] > clave) {
                arr[j] = arr[j-1];
                --j;
            }
            arr[j] = clave;
        }
    }

    void ordenamientoBurbuja(vector<int>& arr) {
        for (size_t i = 0; i < arr.size()-1; ++i) {
            for (size_t j = 0; j < arr.size()-i-1; ++j) {
                if (arr[j] > arr[j+1]) {
                    swap(arr[j], arr[j+1]);
                }
            }
        }
    }

    void ordenamientoBurbujaOptimizado(vector<int>& arr) {
        bool intercambiado;
        int n = arr.size();
        do {
            intercambiado = false;
            for (int i = 0; i < n - 1; ++i) {
                if (arr[i] > arr[i + 1]) {
                    swap(arr[i], arr[i + 1]);
                    intercambiado = true;
                }
            }
            --n;
        } while (intercambiado);
    }

    void ordenamientoPorSeleccion(vector<int>& arr) {
        for (int i = 0; i < arr.size() - 1; ++i) {
            int minIdx = i;
            for (int j = i + 1; j < arr.size(); ++j) {
                if (arr[j] < arr[minIdx]) {
                    minIdx = j;
                }
            }
            swap(arr[i], arr[minIdx]);
        }
    }

    void merge(vector<int>& arr, int left, int mid, int right) {
        vector<int> L(arr.begin() + left, arr.begin() + mid + 1);
        vector<int> R(arr.begin() + mid + 1, arr.begin() + right + 1);

        int i = 0, j = 0, k = left;
        while (i < L.size() && j < R.size()) {
            arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
        }

        while (i < L.size()) arr[k++] = L[i++];
        while (j < R.size()) arr[k++] = R[j++];
    }

    void mergeSort(vector<int>& arr, int left, int right) {
        if (left >= right) return;
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }

    int partition(vector<int>& arr, int low, int high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; ++j) {
            if (arr[j] < pivot) {
                ++i;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return i + 1;
    }

    void quickSort(vector<int>& arr, int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

    void heapify(vector<int>& arr, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }

        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

    void heapSort(vector<int>& arr) {
        int n = arr.size();
        for (int i = n / 2 - 1; i >= 0; --i) {
            heapify(arr, n, i);
        }
        for (int i = n - 1; i >= 0; --i) {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }

    void shellSort(vector<int>& arr) {
        int n = arr.size();
        for (int gap = n / 2; gap > 0; gap /= 2) {
            for (int i = gap; i < n; ++i) {
                int temp = arr[i];
                int j;
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                    arr[j] = arr[j - gap];
                }
                arr[j] = temp;
            }
        }
    }
