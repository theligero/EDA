// Ignacio Ligero Martín
// VJ25

#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

template <class T>
int nodos(bintree<T> const& tree) {
    if (!tree.empty()) 
        return nodos(tree.left()) + nodos(tree.right()) + 1;
    else 
        return 0;
}

template <class T>
int hojas(bintree<T> const& tree) {
    if (!tree.empty()) {
        if (tree.left().empty() && tree.right().empty())
            return 1;
        else
            return hojas(tree.left()) + hojas(tree.right());
    }
    else return 0;
}

template <class T>
int altura(bintree<T> const& tree) {
    int ladoIzq, ladoDer;
    if (tree.empty()) return 0;
    else {
        ladoIzq = 1 + altura(tree.left());
        ladoDer = 1 + altura(tree.right());
        if (ladoIzq >= ladoDer) return ladoIzq;
        else return ladoDer;
    }
}



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    bintree<char> tree;
    tree = leerArbol('.');
    std::cout << nodos(tree) << " " << hojas(tree) << " " << altura(tree) << std::endl;
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
