// Ignacio Ligero Martín
// VJ25


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// se trata de una función del tipo O(log(n)) ya que cada vez que
// no se encuentra el dato deseado se parte por la mitad el problema
// y se busca en el lado donde es posible que esté (si es que está)
bool resolver(std::vector<int>const& v, int ini, int fin) {
    int mitad = (fin + ini) / 2;

    if (v[ini] == ini) return true;
    else if (ini == fin && v[ini] != ini) return false;
    else if (v[fin - 1] == fin - 1) return true;
    else if (v[mitad] == mitad) return true;
    else if (v[mitad] > mitad && v[ini] < ini) return resolver(v, ini, mitad);
    else if (v[mitad] < mitad && v[fin -1] > fin -1) return resolver(v, mitad, fin);

    return false;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    std::cin >> n;
    std::vector<int> sec(n);
    for (int& e : sec) std::cin >> e;
    std::cout << (sec.size() > 0 && resolver(sec, 0, n) ? "SI" : "NO") << std::endl;
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
    //system("PAUSE");
#endif

    return 0;
}
