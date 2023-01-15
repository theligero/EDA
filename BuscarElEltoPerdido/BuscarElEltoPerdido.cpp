// Ignacio Ligero Martín
// VJ25


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// O(log(n)), siendo n el número de eltos del vector
int resolver(std::vector<int> const& v1, std::vector<int> const& v2, int ini, int fin) {
    int n = fin - ini;
    if (n == 0) {
        return v1[ini];
    }
    else if (n == 1) {
        if (v1[ini] == v2[ini]) return v1[ini + 1];
        else return v1[ini];
    }
    else {
        int mitad = (fin + ini) / 2;
        if (v1[mitad] == v2[mitad]) {
            if (v1[mitad + 1] == v2[mitad + 1]) return resolver(v1, v2, mitad + 1, fin);
            else return v1[mitad + 1];
        }
        else {
            if (v1[mitad - 1] == v2[mitad - 1]) return v1[mitad];
            else return resolver(v1, v2, ini, mitad);
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int tam;

    std::cin >> tam;
    std::vector<int> vec1(tam);
    std::vector<int> vec2(tam - 1);

    for (auto& e : vec1) {
        std::cin >> e;
    }

    for (auto& i : vec2) {
        std::cin >> i;
    }

    int sol = resolver(vec1, vec2, 0, tam - 1);
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