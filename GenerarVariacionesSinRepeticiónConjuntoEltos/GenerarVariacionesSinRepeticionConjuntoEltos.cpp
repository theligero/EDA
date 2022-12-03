// Ignacio Ligero Martín
// VJ25


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>



// función que resuelve el problema
void resolver(std::vector<char>& datos, const int& m, const int& n, int k, std::vector<bool>& usadas) {
    for (char c = 'a'; c < 'a' + m; ++c) {
        datos[k] = c;
        if (!usadas[c - 'a']) {
            if (k == n - 1) {
                for (auto& e : datos) {
                    std::cout << e;
                }
                std::cout << std::endl;
            }
            else {
                usadas[c - 'a'] = true;
                resolver(datos, m, n, k + 1, usadas);
                usadas[c - 'a'] = false;
            }
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int m, n;

    std::cin >> m >> n;

    if (!std::cin)
        return false;

    std::vector<char> datos(m);
    std::vector<bool> usadas(m, false);

    resolver(datos, m, n, 0, usadas);

    // escribir sol

    std::cout << std::endl;

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}