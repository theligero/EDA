// Ignacio Ligero Martín
// VJ25


#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

int _n;

int enteroComplementario(int entero, int n) {
    if (entero < 10) {
        _n = n;
        return (9 - entero) * (pow(10, n));
    }
    else {
        int aux = 9 - (entero % 10);
        return enteroComplementario(entero / 10, n + 1) + (aux * (pow(10, n)));
    }
}

int enteroInverso(int entero, int n) {
    if (entero < 10) {
        return entero * pow(10, n);
    }
    else {
        int aux = entero % 10;
        return enteroInverso(entero / 10, n - 1) + (aux * (pow(10, n)));
    }
}


// función que resuelve el problema
void resolver(int& datos) {
    int aux = enteroComplementario(datos, 0);

    std::cout << aux << " " << enteroInverso(aux, _n) << std::endl;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int entero;

    std::cin >> entero;
    // escribir sol

    resolver(entero);
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