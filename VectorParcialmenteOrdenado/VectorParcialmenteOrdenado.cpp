// Ignacio Ligero Martín
// VJ25


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que devuelve el mayor y el menor número de un vector
// se trata de una función del tipo O(n*log(n))
bool menorMayor(std::vector<int>const& v, int ini, int fin) {
    int aux = (ini + fin + 1) / 2;

    if (fin - ini == 1)
        return v[ini] <= v[fin];
    else {
        return v[ini] <= v[fin] && v[ini] <= v[aux] && menorMayor(v, ini, aux - 1) 
            && menorMayor(v, aux, fin);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    std::vector<int> v;
    int aux = -1; bool sol = false;

    std::cin >> aux;

    while (aux != 0) {
        v.push_back(aux);
        std::cin >> aux;
    }

    if (v.size() == 0) return false;
    else if (v.size() == 1) sol = true;
    else sol = menorMayor(v, 0, v.size() - 1);

    // escribir sol

    if (sol == true) std::cout << "SI" << std::endl;
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


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
