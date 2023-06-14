// Ignacio Ligero Martín
// VJ25

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <climits>
#include "bintree_eda.h"

bool esPrimo(const int& n) {
    if (n <= 1) return false;

    int aux = std::sqrt(n);

    for (int i = 2; i <= aux; ++i) {
        if (n % i == 0) return false;
    }

    return true;
}

bool esMultiplo7(const int& n) {
    if (n == 0) return false;
    return n % 7 == 0;
}

void resuelve(const bintree<int>& tree, int prof, int& minProf, int& mejorRes) {
    if (tree.empty()) return;
 
    if (!esPrimo(tree.root())) {
        if (esMultiplo7(tree.root())) {
            if (prof < minProf) {
                minProf = prof;
                mejorRes = tree.root();
            }
        }
        if (prof + 1 < minProf) {
            if (!tree.left().empty()) resuelve(tree.left(), prof + 1, minProf, mejorRes);
            if (!tree.right().empty()) resuelve(tree.right(), prof + 1, minProf, mejorRes);
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<int> tree;
    tree = leerArbol(-1);
    int prof = 1;
    int mejorRes = 0;
    int minProf = INT_MAX;
    resuelve(tree, prof, minProf, mejorRes);
    if (minProf != INT_MAX) std::cout << mejorRes << " " << minProf << std::endl;
    else std::cout << "NO HAY" << std::endl;
}


int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}
