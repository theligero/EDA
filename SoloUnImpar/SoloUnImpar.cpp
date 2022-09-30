// Ignacio Ligero Martín
// VJ25

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// en el peor de los casos sería O(log(n)) puesto que gracias
// al valor que hay en el medio se sabrá que está en una mitad
// del vector o la otra
int resolver(const std::vector<int>& v, int ini, int fin) {
    int mitad = (fin + ini) / 2,
        mitadAux = (v[ini] + v[fin - 1]) / 2;

    if (v[ini] % 2 != 0) return v[ini];
    else if (v[mitad] % 2 != 0) return v[mitad];
    else if (v[fin - 1] % 2 != 0) return v[fin - 1];
    else if (v[mitad] > mitadAux) return resolver(v, ini + 1, mitad);
    else if (v[mitad] <= mitadAux) return resolver(v, mitad, fin - 1);

    return 0;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    std::cin >> n;
    if (n == 0) return false;
    std::vector<int> sec(n);
    for (int& e : sec) std::cin >> e;
    std::cout << resolver(sec, 0, n) << std::endl;
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
    //system("PAUSE");
#endif

    return 0;
}