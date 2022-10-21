// Ignacio Ligero Martín
// VJ25


#include <iostream>
#include <iomanip>
#include <fstream>
#include <list>

// tiene una complejidad del tipo O(n) ya que se recorren todos los elementos de la lista
void invertirSegmento(std::list<int>& l, const int& pos, const int& longitud) {
    int itIzq, itDer;
    std::list<int>::iterator itIni = l.begin();
    std::list<int>::iterator itFin = l.begin();
    while (*itIni != pos) ++itIni;
    while (*itFin != pos + longitud - 1) ++itFin;
    itIzq = *itIni; itDer = *itFin;
    for (int i = 0; i < longitud / 2; ++i) {
        std::swap(*itIni, *itFin);
        ++itIni;
        --itFin;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, pos, longitud, elem;
    std::list<int> l;
    std::cin >> n;
    if (!std::cin) return false;
    std::cin >> pos >> longitud;

    // Leo la lista
    for (int i = 0; i < n; ++i) { std::cin >> elem; l.push_back(elem); }

    // Llamada a la funcion pedida
    invertirSegmento(l, pos, longitud);

    // Muestro la lista
    for (int& e : l) std::cout << e << " ";
    std::cout << std::endl;

    return true;
}

//#define DOMJUDGE
int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("input1.txt");
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