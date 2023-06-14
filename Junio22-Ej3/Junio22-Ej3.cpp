// Ignacio Ligero Martín
// 06023859K
// Pto0204

#include <iostream>
#include <fstream>
#include "bintree_eda.h"
#include <climits>

// Tendrá complejidad de tipo O(n) puesto que, en el peor
// de los casos, hará dos llamadas de tamaño mitad (que, en
// resumidas cuentas, significará que recorrerá la totalidad
// del árbol)
int resuelve(bintree<int> arbol, int ac, int& minAc) {
    int hijoIzq = INT_MAX;
    int hijoDer = INT_MAX;
    if (arbol.right().empty() && arbol.left().empty()) {
        if (ac < minAc) { minAc = ac; return arbol.root(); }
    }
    else {
        if (!arbol.left().empty())
            hijoIzq = resuelve(arbol.left(), ac + 1, minAc);
        if (!arbol.right().empty())
            hijoDer = resuelve(arbol.right(), ac + 1, minAc);

        if (hijoIzq != INT_MAX && hijoIzq >= 3 && ac < minAc) return hijoIzq;
        else if (hijoDer != INT_MAX && hijoDer >= 3 && ac < minAc) return hijoDer;
    }
}

void resuelveCaso() {
    bintree<int> arbol;
    arbol = leerArbol(-1); // -1 es la repr. de arbol vacio
    int aux = INT_MIN;
    int ac = 0;
    int minAc = INT_MAX;
    aux = resuelve(arbol, ac, minAc);
    if (aux != INT_MIN) std::cout << aux;
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
