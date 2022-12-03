// Ignacio Ligero Martín
// VJ25

#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>
#include <map>
#include <unordered_map>
#include <utility>
#include <list>
#include <set>

using libro = std::string;

// Muestra el contenido de una lista
template <class T>
void mostrar(std::list<T> const& l) {
    for (auto const& e : l) {
        std::cout << e << '\n';
    }
}

class VentaLibros {
private:
    struct infoLibro {
        int ejemplares = 0;
        int vendidos = 0;
        std::list<libro>::iterator pos;
    };
    std::unordered_map<libro, infoLibro> libreria;
    std::map<int, std::list<libro>, std::greater<int>> ventas;
public:
    // O(1)
    void nuevoLibro(const int& n, const libro& x) {
        auto it = libreria.find(x);
        if (it == libreria.cend()) {
            infoLibro infoX;
            ventas[0].push_front(x);
            infoX.pos = ventas[0].begin();
            infoX.ejemplares = n;
            libreria.insert({ x, infoX });
        }
        else it->second.ejemplares += n;
    }
    // O(1)
    void comprar(const libro& x) {
        auto it = libreria.find(x);
        if (it == libreria.cend())
            throw std::invalid_argument("Libro no existente");
        else {
            if (it->second.ejemplares <= 0)
                throw std::out_of_range("No hay ejemplares");
            else {
                if (ventas[it->second.vendidos].size() == 1)
                    ventas.erase(it->second.vendidos);
                else
                    ventas[it->second.vendidos].erase(it->second.pos);
                --it->second.ejemplares;
                ++it->second.vendidos;
                ventas[it->second.vendidos].push_front(it->first);
                it->second.pos = ventas[it->second.vendidos].begin();
            }
        }
    }
    // O(1)
    bool estaLibro(const libro& x) {
        auto it = libreria.find(x);
        return it != libreria.cend();
    }
    // O(1)
    void elimLibro(const libro& x) {
        auto it = libreria.find(x);
        if (it != libreria.cend()) {
            ventas[it->second.vendidos].erase(libreria[x].pos);
            libreria.erase(it);
        }
    }
    // O(1)
    int numEjemplares(const libro& x) {
        auto it = libreria.find(x);
        if (it == libreria.cend())
            throw std::invalid_argument("Libro no existente");
        else
            return it->second.ejemplares;

    }
    // O(l), siendo l los 10 primeros libros situados en el listado de ventas
    std::list<libro> top10() {
        int aux = 0;
        std::list<libro> l;
        for (auto const& e : ventas) {
            if (aux < 10 && e.first != 0) {
                for (auto const& i : e.second) {
                    if (aux < 10) {
                        l.push_back(i);
                        ++aux;
                    }
                    else return l;
                }
            }
            else return l;
        }

        return l;
    }
};

bool resuelveCaso() {
    int numOp;

    std::cin >> numOp;
    if (!std::cin) return false;

    VentaLibros amazon;

    std::string operacion, titulo;

    for (int i = 0; i < numOp; ++i) {
        std::cin >> operacion;
        std::cin.ignore(1); // saltar blanco
        if (operacion == "nuevoLibro") {
            int unidades;
            std::cin >> unidades;
            std::cin.ignore(1);
            std::getline(std::cin, titulo);
            amazon.nuevoLibro(unidades, titulo);
        }
        else if (operacion == "comprar") {
            std::getline(std::cin, titulo);
            try {
                amazon.comprar(titulo);
            }
            catch (std::out_of_range const& e) {
                std::cout << e.what() << '\n';
            }
            catch (std::invalid_argument const& e) {
                std::cout << e.what() << '\n';
            }
        }
        else if (operacion == "estaLibro") {
            std::getline(std::cin, titulo);
            if (amazon.estaLibro(titulo)) {
                std::cout << "El libro " << titulo << " esta en el sistema\n";
            }
            else {
                std::cout << "No existe el libro " << titulo << " en el sistema\n";
            }
        }
        else if (operacion == "elimLibro") {
            std::getline(std::cin, titulo);
            amazon.elimLibro(titulo);
        }
        else if (operacion == "numEjemplares") {
            std::getline(std::cin, titulo);
            if (amazon.estaLibro(titulo)) {
                std::cout << "Existen " << amazon.numEjemplares(titulo) << " ejemplares del libro " << titulo << '\n';
            }
            else {
                std::cout << "No existe el libro " << titulo << " en el sistema\n";
            }
        }
        else if (operacion == "top10") {
            std::cout << "TOP10\n";
            mostrar(amazon.top10());
        }
    }
    // fin del caso
    std::cout << "---\n";
    return true;

}

int main() {

    while (resuelveCaso());

    return 0;
}
