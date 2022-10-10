// Ignacio Ligero Martín
// VJ25


#include <iostream>
#include <iomanip>
#include <fstream>
#include "Set.h"



// función que resuelve el problema del tipo
// klog(n) ya que se recorre el vector k veces
// (no se sabe cuántas, o bien se acaba al encontrar el
// elto en datos o bien sigue hasta llegar a 1), y al hacer
// las búsquedas, la estructura Set las hará de tipo logarítmicas
// con los n eltos que tenga (va aumentando a medida que la función
// no va dando con la solución)
bool esFeliz(int num, Set<int>& datos) {
    int aux, numAux = num, sol = 0;

    std::cout << num << " ";

    if (datos.contains(num)) return false;
    else if (num == 1) { return true; }
    else {
        while (numAux > 0) {
            aux = numAux % 10;
            sol += aux * aux;
            numAux = numAux / 10;
        }
        datos.add(num);
        return esFeliz(sol, datos);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    Set<int> v1;
    int num;

    std::cin >> num;

    if (!std::cin)
        return false;

    // escribir sol

    if (esFeliz(num, v1)) std::cout << 1 << std::endl;
    else std::cout << 0 << std::endl;


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