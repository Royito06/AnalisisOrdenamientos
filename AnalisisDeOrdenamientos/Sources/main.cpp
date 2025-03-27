#include <iostream>
#include "../headers/Gestion.h"

using namespace std;


 // Ejecuta las pruebas y muestra mensajes de progreso

int main() {
    cout << "Iniciando pruebas de ordenamiento..." << endl;
    ejecutarPruebas();
    cout << "Pruebas completadas. Resultados guardados en resultados.csv" << endl;
    return 0;
}
