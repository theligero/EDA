// Ignacio Ligero Martín
// VJ25


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema (se trata de una lineal de orden O(n))
void resolver(std::vector<int> datos) {
    int picos = 0, valles = 0, i = 1;

    while (i < datos.size() - 1) {
        if (datos[i] > datos[i + 1] && datos[i] > datos[i - 1])
            ++picos;
        else if (datos[i] < datos[i + 1] && datos[i] < datos[i - 1])
            ++valles;
        ++i;
    }

    std::cout << picos << " " << valles << std::endl;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int temp;

    std::cin >> temp;

    std::vector<int> datos(temp);

    for (int i = 0; i < temp; ++i) {
        std::cin >> datos[i];
    }

    // escribir sol

    resolver(datos);
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