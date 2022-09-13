// Ignacio Ligero Martín
// VJ25


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
// es de orden O(n) ya que se trata de una función lineal que recorre todos los
// eltos del vector independientemente del tamaño
bool resolver(std::vector<int>& datos, int pos) {
    int aux1 = datos[pos], aux2 = datos[datos.size() - 1], i = 0,
        aux3 = datos[0], aux4 = datos[datos.size() - 1];

    if (pos == datos.size() - 1) return true;
    else {
        while (i <= pos) {
            if (aux1 < datos[i]) aux1 = datos[i];
            else aux3 = datos[i];
            ++i;
        }

        while (i < datos.size()) {
            if (aux2 > datos[i]) aux2 = datos[i];
            else aux4 = datos[i];
            ++i;
        }
    }

    if (aux1 < aux2 && aux1 < aux4 && aux3 < aux2 && aux3 < aux4) return true;
    else return false;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int tamanyo, pos;

    std::cin >> tamanyo;
    std::cin >> pos;

    std::vector<int> enteros(tamanyo);

    for (int i = 0; i < tamanyo; ++i) {
        std::cin >> enteros[i];
    }

    // escribir sol

    if (resolver(enteros, pos)) std::cout << "SI" << std::endl;
    else std::cout << "NO" << std::endl;
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