// Ignacio Ligero Martín
// VJ25


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <tuple>


// función que resuelve el problema
// se trata de una funcion de orden O(n) ya que recorre el vector respecto al tamaño
// de éste
std::tuple<int, int> resolver(std::vector<int>const& datos, const int& deLorean) {
    int i = 0, // puntero que va recorriendo todos los eltos de datos
        pri = 0, maxPri = 0, // primer elto del vector mayor
        ult = 0, maxUlt = 0,// ultimo elto del vector menor
        aux = 0, maxAux = 0;// tamaño mayor vector

    while (i < datos.size()) {
        if (datos[i] > deLorean) {
            if (aux == 0) pri = i;
            ++aux;
        }
        else {
            if (aux > maxAux) { ult = i - 1; maxPri = pri; maxUlt = ult; maxAux = aux; }
            pri = 0; ult = 0; aux = 0;
        }
        ++i;
    }

    if (datos[i - 1] > deLorean && aux > maxAux) { ult = i - 1; maxPri = pri; maxUlt = ult; maxAux = aux; }

    return std::make_tuple(maxPri, maxUlt);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int arboles, deLorean;

    std::cin >> arboles >> deLorean;

    std::vector<int> v(arboles);

    for (int i = 0; i < arboles; ++i) {
        std::cin >> v[i];
    }

    // escribir sol

    std::tuple<int, int> aux = resolver(v, deLorean);

    int pri = std::get<0>(aux), ult = std::get<1>(aux);

    std::cout << pri << " " << ult << std::endl;
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