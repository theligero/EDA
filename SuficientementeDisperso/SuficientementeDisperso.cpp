// Ignacio Ligero Martín
// VJ25


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cmath>



// función que resuelve el problema
// en teoría se trata de una función logarítimica del tipo
// O(n*log(n))
bool resolver(std::vector<int> const& datos, const int disp, int ini, int fin) {
    if (fin - ini == 1) {
        return abs(datos[ini] - datos[fin]) >= disp;
    }
    else if (fin - ini == 0) return true;
    else {
        int aux = ((fin - ini) + 1) / 2;
        return abs(datos[ini] - datos[fin]) >= disp && resolver(datos, disp, ini, ini + aux - 1) && 
            resolver(datos, disp, ini + aux, fin);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int casos, disp;

    std::cin >> casos;
    std::cin >> disp;

    if (!std::cin)
        return false;

    std::vector<int> v(casos);

    for (int i = 0; i < casos; ++i) {
        std::cin >> v[i];
    }

    // escribir sol

    // if (resolver(v, disp)) std::cout << "SI" << std::endl;
    if (resolver(v, disp, 0, v.size() - 1)) std::cout << "SI" << std::endl;
    else std::cout << "NO" << std::endl;

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
    #endif 


    while (resuelveCaso()) ;


    // Para restablecer entrada. Comentar para acepta el reto
    #ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
    #endif

    return 0;
}