// Ignacio Ligero Martín
// VJ25


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


bool esValida(std::vector<int>& soluc, int k) {
    bool valida = true;
    int i = 0;
    while (valida && i < k) {
        if (soluc[k] == soluc[i] || (k - i == abs(soluc[k] - soluc[i]))) valida = false;
        else ++i;
    }
    return valida;
}

// función que resuelve el problema
void nreinas(std::vector<int>& soluc, const int& n, int k, int& ac) {
    for (int i = 0; i < n; ++i) {
        soluc[k] = i;
        if (esValida(soluc, k)) {
            if (k == n - 1) {
                ++ac;
            }
            else {
                // marcar(...);
                nreinas(soluc, n, k + 1, ac);
                // desmarcar(...);
            }
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    std::cin >> n;

    std::vector<int> soluc(n);
    int ac = 0;

    nreinas(soluc, n, 0, ac);

    // escribir sol

    std::cout << ac << std::endl;
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
    system("PAUSE");
#endif

    return 0;
}