// Ignacio Ligero Martín
// VJ25

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <set>

using Diccionario = std::unordered_map<std::string, int>;

// O(n), siendo n el número de eltos del diccionario 2
void compararDiccionarios(Diccionario& d1, const Diccionario& d2) {
    int aux = d1.size();
    std::set<std::string> nuevos, quitados, mismos, cambios;
    for (Diccionario::const_iterator e = d2.begin(); e != d2.end(); ++e) {
        auto it = d1.find(e->first); // busco en d1 la palabra del iterador de d2
        if (it != d1.end()) { // si la he encontrado
            if (e->second != it->second) { // y son distintas
                cambios.emplace(e->first); // la añado a los cambios
            }
            mismos.emplace(it->first);
            d1.erase(it); // borro de d1 la palabra
        }
        else nuevos.emplace(e->first);
    }

    for (auto& e : d1) {
        quitados.insert(e.first);
    }

    if (quitados.size() != 0 || nuevos.size() != 0 || cambios.size() != 0) {
        if (nuevos.size() != 0) {
            std::cout << "+ ";
            for (auto const& e : nuevos) {
                std::cout << e << " ";
            }
            std::cout << std::endl;
        }

        if (quitados.size() != 0) {
            std::cout << "- ";
            for (auto const& i : quitados) {
                std::cout << i << " ";
            }
            std::cout << std::endl;
        }

        if (cambios.size() != 0) {
            std::cout << "* ";
            for (auto const& a : cambios) {
                std::cout << a << " ";
            }
            std::cout << std::endl;
        }
    }

    else std::cout << "Sin cambios" << std::endl;
}

// O(n), siendo n el número de eltos a insertar
void leerDiccionario(Diccionario& diccionario) {
    char c;
    std::string clave;
    int valor;
    std::cin.get(c);
    while (c != '\n') {
        std::cin.unget();
        std::cin >> clave >> valor;
        diccionario.insert({ clave, valor });
        std::cin.get(c);
    }
}

void resuelveCaso() {
    Diccionario antiguo;
    Diccionario nuevo;
    leerDiccionario(antiguo);
    leerDiccionario(nuevo);
    compararDiccionarios(antiguo, nuevo);
    std::cout << "---" << std::endl;
}


int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
//#ifndef DOMJUDGE
//    std::ifstream in("datos.txt");
//    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
//#endif

    int numCasos; char c;
    std::cin >> numCasos;
    std::cin.get(c);
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // Para restablecer entrada. Comentar para acepta el reto
//#ifndef DOMJUDGE // para dejar todo como estaba al principio
//    std::cin.rdbuf(cinbuf);
//    //system("PAUSE");
//#endif

    return 0;
}
