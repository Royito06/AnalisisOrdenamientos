#include <vector>
#include <random>

std::vector<int> generarArregloAleatorio(int tamano, int max_valor = 10000) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distribucion(1, max_valor);

    std::vector<int> arreglo(tamano);
    for (int& val : arreglo) {
        val = distribucion(gen);
    }
    return arreglo;
}
