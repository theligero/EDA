// Ignacio Ligero Martín
// VJ25


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>



// función que resuelve el problema
// se trata de una función lineal de orden O(n)
bool resolver(std::vector<int>& datos) {
    int i = 0, j = 0, k = 0;
    bool aux = true;

    while (i < datos.size() - 1) {
        if (datos[i] > datos[i + 1]) ++j;
        else if (datos[i] < datos[i + 1]) ++k;
        ++i;
    }

    if (j >= k) return j == i;
    else return k == i;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int hermanos;
    std::cin >> hermanos;

    if (!std::cin || hermanos == 0)
        return false;

    std::vector<int> alturas(hermanos);

    for (int i = 0; i < alturas.size(); ++i) {
        std::cin >> alturas[i];
    }

    // escribir sol

    if (resolver(alturas)) std::cout << "DALTON" << std::endl;
    else std::cout << "DESCONOCIDOS" << std::endl;

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