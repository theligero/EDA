// Ignacio Ligero Martín
// VJ25


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

enum colores { azul, rojo, verde };

// función que resuelve el problema
void resolver(std::vector<colores>& v, int k, const int& m) {
    for (int i = 0; i < 3; ++i) {
        v[k] = (colores)i;
        if (k == m - 1) {
            for (auto& e : v) {
                std::cout << e << " ";
            }
            std::cout << std::endl;
        }
        else {
            resolver(v, k + 1, m);
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int num;

    std::cin >> num;

    if (num == 0)
        return false;

    std::vector<colores> col(num);

    resolver(col, 0, num);
    std::cout << std::endl;

    // escribir sol

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