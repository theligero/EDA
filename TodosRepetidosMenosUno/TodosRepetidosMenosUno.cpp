// Ignacio Ligero Martín
// VJ26

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// se trata de una función recursiva con complejidad O(log(N)), siendo
// N el número de elementos del vector v. 
int resolver(const std::vector<int>& v, int ini, int fin) {
    if (ini == fin) return ini;
    else if (ini == fin - 1) return ini;
    else {
        int mitad = (fin + ini) / 2; // busco el elto que está en la mitad

        if (mitad % 2 != 0) --mitad; // si mitad es impar reduzco en uno

        if (v[mitad] != v[mitad + 1]) return resolver(v, ini, mitad);
        else return resolver(v, mitad + 2, fin);
    }
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for (int& e : v) std::cin >> e;

    // Llamada a la función resolver y mostrar el resultado
    std::cout << resolver(v, 0, v.size()) << std::endl;
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