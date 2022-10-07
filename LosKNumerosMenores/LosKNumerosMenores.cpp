// Ignacio Ligero Martín
// VJ25


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Set.h"


// se trata de una función del tipo nlog(k) ya que será lineal por
// la parte de n ya que el recorrido del vector será inevitable mientras
// que se hará la busqueda binaria del vector ordenado de elems (k) 
// a devolver por la función
Set<int> resolver(const std::vector<int>& datos, const int& tam) {
    Set<int> aux; int i = 0;

    while (i < datos.size()) {
        if (aux.size() < tam) aux.add(datos[i]);
        else if (aux.getMax() > datos[i] && !aux.contains(datos[i])) {
            aux.removeMax();
            aux.add(datos[i]);
        }
        ++i;
    }

    return aux;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int tam, aux; 
    std::vector<int> v;

    std::cin >> tam;

    if (tam == 0)
        return false;

    std::cin >> aux;

    while (aux != -1) {
        v.push_back(aux);
        std::cin >> aux;
    }

    Set<int> s = resolver(v, tam);

    for (int i = 0; i < s.size(); ++i) {
        std::cout << s.toArray()[i];
        if (i != tam - 1) std::cout << " ";
    }

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