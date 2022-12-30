// Ignacio Ligero Martín
// VJ25

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <map>

using Estado = std::string;
using Partido = std::string;

class ConteoVotos {

private:
    struct infoEstado {
        int compromisarios;
        Partido masVotado;
        std::unordered_map<Partido, int> partidos;
    };
    std::unordered_map<Estado, infoEstado> pais;
public:
    // O(1)
    void nuevo_estado(const Estado& nombre, int num_compromisarios) {
        auto it = pais.find(nombre);
        if (it == pais.cend()) {
            infoEstado aux;
            aux.compromisarios = num_compromisarios;
            pais.insert({ nombre, aux });
        }
        else throw std::domain_error("Estado ya existente");
    }

    // O(1)
    void sumar_votos(const Estado& estado, const Partido& partido, int num_votos) {
        auto it = pais.find(estado);
        if (it != pais.cend()) {
            auto it2 = it->second.partidos.find(partido);
            if (it2 != it->second.partidos.cend())
                it2->second += num_votos;
            else
                it->second.partidos.insert({ partido, num_votos });

            auto it3 = it->second.partidos.find(it->second.masVotado);
            if (it3 != it->second.partidos.cend()) {
                if (it3->second < it->second.partidos[partido])
                    it->second.masVotado = partido;
            }
            else it->second.masVotado = partido;
        }
        else throw std::domain_error("Estado no encontrado");
    }

    // O(1)
    Partido ganador_en(const Estado& estado) const {
        auto it = pais.find(estado);
        if (it != pais.cend()) {
            return it->second.masVotado;
        }
        else throw std::domain_error("Estado no encontrado");
    }

    // O(k*n) siendo n el número de partidos del mapa y k el
    // número de estados del país
    std::vector<std::pair<Partido, int>> resultados() const {
        std::map<Partido, int> aux;
        for (const auto& e : pais) {
            aux[e.second.masVotado] += e.second.compromisarios;
        }

        std::vector<std::pair<Partido, int>> vec;

        for (const auto& i : aux) {
            vec.push_back({ i.first, i.second });
        }

        return vec;
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
