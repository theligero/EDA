#include <iostream>
#include <fstream>
#include <string>
#include "bintree_eda.h"


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso(char tip) {
    if (tip == 'N') {
        bintree<int> arb;
        arb = leerArbol(-1);

        std::cout << arb.menorElto(arb) << std::endl;
    }
    else if (tip == 'P') { 
        bintree<std::string> arb;
        std::string aux = "#";
        arb = leerArbol(aux);

        std::cout << arb.menorElto(arb) << std::endl;
    }
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    bool aux = true;
    char tipoCaso;

    while (aux) {
        std::cin >> tipoCaso;
        if (!std::cin) break;
        resuelveCaso(tipoCaso);
    }


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}

