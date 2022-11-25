// Ignacio Ligero Martín
// VJ25

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <unordered_map>

using DNI = std::string;

class carnet_puntos {
private:
    const int MIN_PUNTOS = 0;
    const int MAX_PUNTOS = 15;
    std::unordered_map<DNI, int> carnets;
    std::vector<int> numPuntos;
public:
    carnet_puntos() : numPuntos(MAX_PUNTOS + 1) {}
    // O(k), siendo k constante
    void nuevo(std::string dni) {
        auto it = carnets.find(dni);
        if (it != carnets.cend()) throw std::domain_error("Conductor duplicado");
        else { carnets.insert({ dni, MAX_PUNTOS }); ++numPuntos[MAX_PUNTOS]; }
    }
    // O(k), siendo k constante
    void quitar(std::string dni, int puntos) {
        auto it = carnets.find(dni);
        if (it == carnets.cend()) throw std::domain_error("Conductor inexistente");
        else {
            --numPuntos[it->second];
            if (it->second - puntos < MIN_PUNTOS) {
                it->second = MIN_PUNTOS;
            }
            else it->second -= puntos;
            ++numPuntos[it->second];
        }
    }
    // O(k), siendo k constante
    int consultar(std::string dni) {
        auto it = carnets.find(dni);
        if (it == carnets.cend()) throw std::domain_error("Conductor inexistente");
        else return it->second;
    }
    // O(k), siendo k constante
    int cuantos_con_puntos(int puntos) { 
        if (puntos > MAX_PUNTOS || puntos < MIN_PUNTOS)
            throw std::domain_error("Puntos no validos");
        else return numPuntos[puntos];
    }
};

class carnet_puntos_plus : public carnet_puntos {
public:
    std::string consultar(std::string dni) {
        int punt = carnet_puntos::consultar(dni);
        return "Puntos de " + dni + ": " + std::to_string(punt);
    }
    std::string cuantos_con_puntos(int puntos) {
        int cuantos = carnet_puntos::cuantos_con_puntos(puntos);
        return "Con " + std::to_string(puntos) + " puntos hay " + std::to_string(cuantos);
    }
};



bool resuelveCaso() {
    std::string orden, dni;
    int punt;
    std::cin >> orden;
    if (!std::cin)
        return false;

    carnet_puntos_plus dgt;

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
            else if (orden == "consultar") {
                std::cin >> dni;
                std::cout << dgt.consultar(dni) << '\n';
                
            }
            else if (orden == "cuantos_con_puntos") {
                std::cin >> punt;
                std::cout << dgt.cuantos_con_puntos(punt) << '\n';
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
