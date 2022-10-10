// Ignacio Ligero Martín
// VJ25


#include <iostream>
#include <iomanip>
#include <fstream>
#include "Set.h"



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    Set<int> v1, v2;
    int tam, aux;

    std::cin >> tam;

    for (int i = 0; i < tam; ++i) {
        std::cin >> aux; 
        v1.add(aux);
    }

    std::cin >> tam;

    for (int j = 0; j < tam; ++j) {
        std::cin >> aux;
        v2.add(aux);
    }

    if (!std::cin)
        return false;

    // escribir sol
    if (v1 <= v2) std::cout << 1 << std::endl;
    else std::cout << 0 << std::endl;


    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}