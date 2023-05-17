// Ignacio Ligero Martín
// VJ25

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <list>

using dni = std::string;
using puntos = int;

struct info {
    puntos pts;
    std::list<dni>::iterator it;
};

class carnet_puntos {
private:
    const puntos MAX_PUNTOS = 15;
    const puntos MIN_PUNTOS = 0;
    std::unordered_map<dni, info> listado;
    std::vector<std::list<dni>> tablaPuntos;
public:
    carnet_puntos() : tablaPuntos(MAX_PUNTOS + 1) {}
    // O(k), siendo k constante
    void nuevo(const dni& id) {
        if (!listado.count(id)) {
            listado[id].pts = MAX_PUNTOS;
            tablaPuntos[MAX_PUNTOS].push_front(id);
            listado[id].it = tablaPuntos[MAX_PUNTOS].begin();
        }
        else {
            throw std::domain_error("Conductor duplicado");
        }
    }
    // O(k), siendo k constante
    void quitar(const dni& id, const puntos& p) {
        if (listado.count(id)) {
            if (listado[id].pts != MIN_PUNTOS && p != 0) {
                tablaPuntos[listado[id].pts].erase(listado[id].it);
                if (listado[id].pts - p < MIN_PUNTOS) listado[id].pts = MIN_PUNTOS;
                else listado[id].pts -= p;
                tablaPuntos[listado[id].pts].push_front(id);
                listado[id].it = tablaPuntos[listado[id].pts].begin();
            }
        }
        else {
            throw std::domain_error("Conductor inexistente");
        }
    }
    // O(k), siendo k constante
    void recuperar(const dni& id, const puntos& p) {
        if (listado.count(id)) {
            if (listado[id].pts != MAX_PUNTOS && p != 0) {
                tablaPuntos[listado[id].pts].erase(listado[id].it);
                if (listado[id].pts + p > MAX_PUNTOS) listado[id].pts = MAX_PUNTOS;
                else listado[id].pts += p;
                tablaPuntos[listado[id].pts].push_front(id);
                listado[id].it = tablaPuntos[listado[id].pts].begin();
            }
        }
        else {
            throw std::domain_error("Conductor inexistente");
        }
    }
    // O(k), siendo k constante
    puntos consultar(const dni& id) {
        if (listado.count(id)) return listado[id].pts;
        else throw std::domain_error("Conductor inexistente");
    }
    // O(k), siendo k constante
    int cuantos_con_puntos(const puntos& p) {
        if (p >= MIN_PUNTOS && p <= MAX_PUNTOS) {
            return tablaPuntos[p].size();
        }
        else throw std::domain_error("Puntos no validos");
    }
    // O(k), siendo k constante
    std::list<dni> lista_por_puntos(const puntos& p) {
        if (p >= MIN_PUNTOS && p <= MAX_PUNTOS) {
            return tablaPuntos[p];
        }
        else throw std::domain_error("Puntos no validos");
    }
};


bool resuelveCaso() {
    std::string orden, dni;
    int punt;
    std::cin >> orden;
    if (!std::cin)
        return false;

    carnet_puntos dgt;

    while (orden != "FIN") {
        try {
            if (orden == "nuevo") {
                std::cin >> dni;
                dgt.nuevo(dni);
            }
            else if (orden == "quitar") {
                std::cin >> dni >> punt;
                dgt.quitar(dni, punt);
            }
            else if (orden == "recuperar") {
                std::cin >> dni >> punt;
                dgt.recuperar(dni, punt);
            }
            else if (orden == "consultar") {
                std::cin >> dni;
                punt = dgt.consultar(dni);
                std::cout << "Puntos de " << dni << ": " << punt << '\n';
            }
            else if (orden == "cuantos_con_puntos") {
                std::cin >> punt;
                int cuantos = dgt.cuantos_con_puntos(punt);
                std::cout << "Con " << punt << " puntos hay " << cuantos << '\n';
            }
            else if (orden == "lista_por_puntos") {
                std::cin >> punt;
                auto const& lista = dgt.lista_por_puntos(punt);
                std::cout << "Tienen " << punt << " puntos:";
                for (auto const& dni : lista)
                    std::cout << ' ' << dni;
                std::cout << '\n';
            }
            else
                std::cout << "OPERACION DESCONOCIDA\n";
        }
        catch (std::domain_error e) {
            std::cout << "ERROR: " << e.what() << '\n';
        }
        std::cin >> orden;
    }
    std::cout << "---\n";
    return true;
}

int main() {

    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   // _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    //system("pause");
#endif
    return 0;
}
