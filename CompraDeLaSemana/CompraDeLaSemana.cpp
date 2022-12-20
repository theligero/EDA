// Ignacio Ligero Martín
// VJ25


#include <iostream>
#include <fstream>
#include <vector>
#include <climits>

using Matrix = std::vector<std::vector<int>>;


// función que resuelve el problema
void resolver(std::vector<int>& soluc, int k, const int& n, 
    const int& m, const Matrix& super, int& mejorGasto, int gastoAct,
    const std::vector<int>& minEltos) {

    // i es el i-ésimo producto del vector solución
    // k es la profundidad del nº de productos

    for (int i = 0; i < m; ++i) {
        soluc[i] += 1;
        if (soluc[i] <= 3) {
            gastoAct += super[i][k];
            if (k == n - 1) {
                if (gastoAct < mejorGasto) 
                    mejorGasto = gastoAct;
            }
            else {
                int estOptimista = 0;
                for (int l = k + 1; l < n; ++l) {
                    estOptimista += minEltos[l];
                }
                if (estOptimista + gastoAct < mejorGasto)
                    resolver(soluc, k + 1, n, m, super, mejorGasto, gastoAct, minEltos);
            }
            gastoAct -= super[i][k];
        }
        soluc[i] -= 1;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n, m, mejorGasto;
    std::cin >> m >> n;
    mejorGasto = INT_MAX;
    Matrix precios(m, std::vector<int>(n));
    std::vector<int> precioMin(n, INT_MAX);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> precios[i][j];
            if (precioMin[j] > precios[i][j])
                precioMin[j] = precios[i][j];
        }
    }
    // vector del nº de productos de cada supermercado
    std::vector<int> soluc(m, 0);
    resolver(soluc, 0, n, m, precios, mejorGasto, 0, precioMin);
    if (mejorGasto == INT_MAX) std::cout << "Sin solucion factible" << std::endl;
    else std::cout << mejorGasto << std::endl;
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
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}