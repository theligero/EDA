// Ignacio Ligero Martín
// VJ25

#include <iostream>
#include <iomanip>
#include <fstream>
#include <stack>
#include "bintree_eda.h"

template <class T>
void nodos(bintree<T> const& tree, std::vector<T>& v) {
    if (!tree.empty() && tree.left().empty() && tree.right().empty()) {
        v.push_back(tree.root());
    }
    else {
        nodos(tree.left(), v);
        nodos(tree.right(), v);
    }
}




// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    std::vector<int> v;
    bintree<int> tree;
    tree = leerArbol(-1);
    tree.laFrontera(tree, v);

    for (auto const& e : v) {
        std::cout << e << " ";
    }
    std::cout << std::endl;
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
