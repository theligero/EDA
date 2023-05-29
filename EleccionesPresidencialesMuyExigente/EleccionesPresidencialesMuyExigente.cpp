// Ignacio Ligero Martín
// VJ25

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>

using Estado = std::string;
using Partido = std::string;

struct infoEstado {
    int compr; // compromisarios
    Partido masVotado = "NULL"; // partido más votado del Estado
    std::unordered_map<Partido, int> conteo; // mapa no ordenado del listado de partidos con sus votos
};

class ConteoVotos {

private:
    std::unordered_map<Estado, infoEstado> estadosPais; // mapa no ordenado del listado de estados de un país
    std::map<Partido, int> comprTotal; // mapa ordenado del recuento total de votos 
public:
    // O(1)
    void nuevo_estado(const Estado& nombre, int num_compromisarios) {
        if (!estadosPais.count(nombre)) {
            infoEstado aux;
            aux.compr = num_compromisarios;
            estadosPais.insert({ nombre, aux });
        }
        else {
            throw std::domain_error("Estado ya existente");
        }
    }
    // O(log(n)), siendo n el número de compromisarios (en el peor de los casos)
    // O(1) (en el mejor de los casos)
    void sumar_votos(const Estado& estado, const Partido& partido, int num_votos) {
        if (estadosPais.count(estado)) {
            estadosPais[estado].conteo[partido] += num_votos;
            if (estadosPais[estado].masVotado == "NULL") {
                estadosPais[estado].masVotado = partido;
                comprTotal[partido] += estadosPais[estado].compr;
            }
            else if (estadosPais[estado].masVotado != partido) {
                if (estadosPais[estado].conteo[partido] > estadosPais[estado].conteo[estadosPais[estado].masVotado]) {
                    comprTotal[estadosPais[estado].masVotado] -= estadosPais[estado].compr;
                    if (comprTotal[estadosPais[estado].masVotado] == 0) comprTotal.erase(estadosPais[estado].masVotado);
                    estadosPais[estado].masVotado = partido;
                    comprTotal[partido] += estadosPais[estado].compr;
                }
            }
        }
        else {
            throw std::domain_error("Estado no encontrado");
        }
    }
    // O(1)
    Partido ganador_en(const Estado& estado) const {
        if (estadosPais.count(estado)) {
            return estadosPais.at(estado).masVotado;
        }
        else throw std::domain_error("Estado no encontrado");
    }
    // O(k), siendo k el número de elementos del listado de partidos
    std::vector<std::pair<Partido, int>> resultados() const {
        std::vector <std::pair<Partido, int>> v;
        std::pair<Partido, int> aux;
        for (auto it = comprTotal.cbegin(); it != comprTotal.cend(); ++it) {
            aux = std::make_pair(it->first, it->second);
            v.push_back(aux);
        }
        return v;
    }

};


bool resuelveCaso() {
    std::string comando;
    std::cin >> comando;
    if (!std::cin) return false;

    ConteoVotos elecciones;

    while (comando != "FIN") {
        try {
            if (comando == "nuevo_estado") {
                Estado estado;
                int num_compromisarios;
                std::cin >> estado >> num_compromisarios;
                elecciones.nuevo_estado(estado, num_compromisarios);
            }
            else if (comando == "sumar_votos") {
                Estado estado;
                Partido partido;
                int num_votos;
                std::cin >> estado >> partido >> num_votos;
                elecciones.sumar_votos(estado, partido, num_votos);
            }
            else if (comando == "ganador_en") {
                Estado estado;
                std::cin >> estado;
                Partido ganador = elecciones.ganador_en(estado);
                std::cout << "Ganador en " << estado << ": " << ganador << "\n";
            }
            else if (comando == "resultados") {
                for (const auto& par : elecciones.resultados()) {
                    std::cout << par.first << " " << par.second << "\n";
                }
            }
        }
        catch (std::exception& e) {
            std::cout << e.what() << "\n";
        }
        std::cin >> comando;
    }

    std::cout << "---\n";
    return true;
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso()) {}

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
