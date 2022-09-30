// Ignacio Ligero Martín
// VJ25


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// se trata de una función del tipo O(n) ya que recorre la totalidad del vector y en base
// a las comparaciones determina si el listado de números es caucásico o no
int resolver(std::vector<int> const& v, int ini, int fin) {
    int mitad = (fin + ini) / 2,
        ladoIzq = 0, ladoDer = 0;

    if (fin - ini == 2) {
        if (v[ini] % 2 == 0) ++ladoIzq;
        if (v[fin - 1] % 2 == 0) ++ladoDer;
        return (ladoIzq + ladoDer);
    }
    else {
        ladoIzq = resolver(v, ini, mitad); ladoDer = resolver(v, mitad, fin);
        if (ladoIzq == -1 || ladoDer == -1 || abs(ladoIzq - ladoDer) > 2) return -1;
        else return (ladoIzq + ladoDer);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numEltos = 0;

    std::cin >> numEltos;

    std::vector<int> v(numEltos);

    if (numEltos == 0)
        return false;
    else {
        for (int i = 0; i < v.size(); ++i) {
            std::cin >> v[i];
        }
    }

    if (resolver(v, 0, v.size()) != -1) std::cout << "SI" << std::endl;
    else std::cout << "NO" << std::endl;

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