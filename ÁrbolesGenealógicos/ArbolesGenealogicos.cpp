// Ignacio Ligero Martín
// VJ25

#include <iostream>
#include <iomanip>
#include <fstream>
#include <climits>
#include "bintree_eda.h"


bool resuelve(const bintree<int>& tree, int prof, int& maxProf) {
    if (tree.empty()) return true;

    if (prof > maxProf) maxProf = prof;

    if (!tree.left().empty() && !tree.right().empty()) {
        return tree.root() >= tree.left().root() + 18 && tree.root() >= tree.right().root() + 18 && 
            tree.left().root() >= tree.right().root() + 2 && resuelve(tree.left(), prof + 1, maxProf) && 
            resuelve(tree.right(), prof + 1, maxProf);
    }
    else if (!tree.left().empty() && tree.right().empty()) {
        return tree.root() >= tree.left().root() + 18 && resuelve(tree.left(), prof + 1, maxProf);
    }
    else if (tree.left().empty() && !tree.right().empty()) {
        return false;
    }
    else {
        return true;
    }
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<int> tree;
    tree = leerArbol(-1);
    int prof = 1;
    int maxProf = 0;
    if (resuelve(tree, prof, maxProf)) std::cout << "SI " << maxProf << std::endl;
    else std::cout << "NO" << std::endl;
    // cout << nodos(tree) << " " << hojas(tree) << " " << altura(tree) << endl;
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
