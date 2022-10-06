// Ignacio Ligero Martín
// VJ25


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>



// se trata de una función del tipo O(log(n)) ya que se compara el
// inicio, la mitad y el final y en base a esos valores y si es posible
// se devuelve uno de ellos, de lo contrario se parte el problema por
// la mitad y se busca en la mitad que se sospeche el número deseado
int resolver(std::vector<int>const& v, int ini, int fin) {
    int mitad = (fin + ini) / 2;

    if (fin - ini == 1) return v[ini];
    else if (fin - ini == 2) {
        if (v[ini] < v[fin - 1]) return v[ini];
        else if (v[fin - 1] < v[ini]) return v[fin - 1];
    }
    else {
        if (v[mitad] < v[ini] && v[mitad] < v[fin - 1] && v[mitad] == v[fin - 2]) return v[mitad];
        else if (v[mitad] > v[fin - 1] && v[mitad] > v[ini]) return resolver(v, ini, mitad);
        else if (v[mitad] < v[fin - 1] && v[mitad] < v[ini]) return resolver(v, mitad, fin);
        else if (v[ini] < v[fin - 1] && v[ini] < v[mitad]) return v[ini];
        else if (v[fin - 1] < v[ini] && v[fin - 1] < v[mitad]) return v[fin - 1];
    }

    return v[ini];
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int tam = 1, aux = 0;
    std::vector<int> v;

    std::cin >> tam;

    if (!std::cin)
        return false;

    for (int i = 0; i < tam; ++i) {
        std::cin >> aux;
        v.push_back(aux);
    }

    // escribir sol

    std::cout << resolver(v, 0, v.size()) << std::endl;

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