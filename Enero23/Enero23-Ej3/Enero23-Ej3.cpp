// Ignacio Ligero Martín
// VJ25

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <vector>

using Equipo = std::string;
using Problema = std::string;

struct infoEquipo {
    int aciertos = 0;
    int tiempo = 0;
};

struct infoProblema {
    bool resuelto = false;
    int tiempo = 0;
};

std::unordered_map<Equipo, infoEquipo> equipos;
std::unordered_map<Problema, std::unordered_map<Equipo, infoProblema>> problemas;

bool ordenar(Equipo a, Equipo b) {
    if (equipos[a].tiempo == equipos[b].tiempo) {
        return a < b;
    }
    else return equipos[a].tiempo < equipos[b].tiempo;
}

void procesaEnvios(std::map<int, std::vector<Equipo>, std::greater<int>>& clasificacion) {
    std::string equipo, problema, veredicto;
    int minuto;

    std::cin >> equipo;
    while (equipo != "FIN") {
        std::cin >> problema >> minuto >> veredicto;
        if (veredicto == "AC" && !problemas[problema][equipo].resuelto) {
            problemas[problema][equipo].tiempo += minuto;
            problemas[problema][equipo].resuelto = true;
            equipos[equipo].aciertos += 1;
            equipos[equipo].tiempo += problemas[problema][equipo].tiempo;
        }
        else {
            if (!problemas[problema][equipo].resuelto) {
                problemas[problema][equipo].tiempo += 20;
            }
            equipos[equipo].aciertos += 0;
            equipos[equipo].tiempo += 0;
        }
        std::cin >> equipo;
    }


    for (auto& e : equipos) {
        clasificacion[e.second.aciertos].push_back(e.first);
    }

    for (auto& i : clasificacion) {
        std::sort(i.second.begin(), i.second.end(), ordenar);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    equipos.clear();
    problemas.clear();
    std::map<int, std::vector<Equipo>, std::greater<int>> clasificacion;

    procesaEnvios(clasificacion);

    // Se imprime la salida
    for (auto& e : clasificacion) {
        for (auto& i : e.second) {
            std::cout << i << " " << e.first << " " << equipos[i].tiempo << std::endl;
        }
    }
    std::cout << "---\n";
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("input3.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}