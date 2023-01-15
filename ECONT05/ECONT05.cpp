// Ignacio Ligero Martín
// VJ25


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// O(log(n)), siendo n el número de eltos del vector
int resolver(std::vector<int>const& v, int ini, int fin) {
    int n = fin - ini;
    if (n == 0) return ini;
    else if (n == 1) return ini;
    else {
        int mitad = (fin + ini) / 2;
        if (mitad % 2 == 0) { // mitad es par
            if (v[mitad] != v[mitad - 1]) return resolver(v, mitad, fin);
            else return resolver(v, ini, mitad);
        }
        else { // mitad es impar
            if (v[mitad] == v[mitad - 1]) return resolver(v, mitad, fin);
            else return resolver(v, ini, mitad);
        }
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int tam;

    std::cin >> tam;

    std::vector<int> v(tam);

    for (auto& e : v) {
        std::cin >> e;
    }

    int sol = resolver(v, 0, v.size());

    // escribir sol
    std::cout << sol << std::endl;
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