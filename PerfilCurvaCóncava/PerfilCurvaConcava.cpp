// Ignacio Ligero Martín
// VJ25

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// se trata de una función del tipo O(log(n)) ya que si no se cumplen
// las condiciones base se parte el problema por la mitad y en esa misma
// mitad se busca la solución de la misma manera que antes
int minimo(const std::vector<int>& sec, int ini, int fin) {
    int mitad = (fin + ini) / 2;

    if (fin == 1 || (fin - 1) - ini == 1 && sec[fin - 1] > sec[ini] || 
        sec[ini] < sec[ini + 1] && sec[ini] < sec[mitad] && sec[mitad] < sec[fin - 1])
        return sec[ini];
    else if (sec[fin - 1] >= sec[ini] && fin - ini < 2 || 
        sec[fin - 1] < sec[fin - 2] && sec[fin - 1] <= sec[mitad] && sec[mitad] <= sec[ini])
        return sec[fin - 1];
    else if (mitad > ini && mitad < fin - 1 && sec[mitad] < sec[mitad + 1] && sec[mitad] < sec[mitad - 1])
        return sec[mitad];
    else if (sec[ini] > sec[ini + 1] && sec[mitad] > sec[mitad - 1]) 
        return minimo(sec, ini, mitad);
    else if (sec[mitad] > sec[mitad + 1] && sec[fin - 1] > sec[fin - 2]) 
        return minimo(sec, mitad, fin);

    return sec[ini];
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    std::cin >> n;
    if (!std::cin) return false;
    std::vector<int> sec(n);
    for (int& e : sec) std::cin >> e;
    std::cout << minimo(sec, 0, n) << std::endl;
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