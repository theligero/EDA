// Ignacio Ligero Martín
// VJ25

#include <iostream>
#include <fstream>
#include <vector>

// entiendo que es una funcion entre cuadrática y lineal, pero no estoy seguro
// si tuviese que adivinar, diría que sería algo menor que orden O(Σn)
bool anagramas(std::string& cad1, std::string& cad2) {
    int aux = 0, i = 0, j = 0;

    while (i < cad1.size() && j < cad2.size()) {
        if (cad1[i] == cad2[j]) { ++aux; ++i; cad2.erase(cad2.begin() + j); j = 0; }
        else { ++j; }
    }

    return aux == cad1.size();
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    std::string word1, word2;
    std::cin >> word1 >> word2;
    std::cout << (anagramas(word1, word2) ? "SI" : "NO") << std::endl;
}

//#define DOMJUDGE
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