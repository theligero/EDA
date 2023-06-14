// Ignacio Ligero Martín
// VJ25

#include <iostream>
#include <fstream>
#include "bintree_eda.h"
#include <climits>

/// <summary>
/// Función que resuelve el problema
/// </summary>
/// <param name="arbol">Árbol utilizado para la estructura de enteros</param>
/// <param name="numDragones">Número actual de dragones contados hasta el nodo actual</param>
/// <param name="mejorDragones">Mejor resultado acumulado hasta el momento</param>
/// <param name="nodo">Valor del entero con mejor resultado</param>
void resuelve(bintree<int> arbol, int numDragones, int& mejorDragones, int& nodo) {
    const int& raiz = arbol.root();

    if (raiz == 1) {
        ++numDragones;
        if (!arbol.left().empty()) resuelve(arbol.left(), numDragones, mejorDragones, nodo);
        if (!arbol.right().empty()) resuelve(arbol.right(), numDragones, mejorDragones, nodo);
    }
    else if (raiz == 2 || raiz == 0) {
        if (!arbol.left().empty()) resuelve(arbol.left(), numDragones, mejorDragones, nodo);
        if (!arbol.right().empty()) resuelve(arbol.right(), numDragones, mejorDragones, nodo);
    }
    else if (raiz >= 3) {
        if (numDragones < mejorDragones) {
            mejorDragones = numDragones;
            nodo = raiz;
        }
    }
}

void resuelveCaso() {
    bintree<int> arbol;
    arbol = leerArbol(-1); // -1 es la repr. de arbol vacio
    int numDragones = 0;
    int mejorDragones = INT_MAX;
    int nodo = 0;
    resuelve(arbol, numDragones, mejorDragones, nodo);
    std::cout << nodo;
    std::cout << std::endl;
}

//#define DOMJUDGE
int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("input2.txt");
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
