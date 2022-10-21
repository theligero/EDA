#include <iostream>
#include <iomanip>
#include <fstream>
#include "list_eda.h"


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n, a;
    list<int> q;
    std::cin >> n;
    while (n != -1) {
        q.push_back(n);
        std::cin >> n;
    }

    std::cin >> a;

    for (list<int>::const_iterator it = q.cbegin(); it != q.cend(); ++it) {
        std::cout << *it << " ";
    }

    std::cout << std::endl;

    // llamada a metodo
    q.deleteRepeated(a);

    for (list<int>::const_iterator it = q.cbegin(); it != q.cend(); ++it) {
        std::cout << *it << " ";
    }

    std::cout << std::endl;
}

//#define DOMJUDGE
int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i) {
        resuelveCaso();
    }

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}
