// Ignacio Ligero Martín
// VJ25

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <map>


using Pelicula = std::string;
using Actor = std::string;
using Reparto = std::map<Actor, int>;
using RepartosPeliculas = std::map<Pelicula, Reparto>;

void leerRepartos(int numPeliculas, RepartosPeliculas& peliculas) {
    Pelicula peli; int numActores;
    Actor actor; int minutos;
    for (int i = 0; i < numPeliculas; ++i) {
        std::cin >> peli; std::cin >> numActores;
        Reparto aux;
            for (int j = 0; j < numActores; ++j) {
                std::cin >> actor >> minutos;
                aux.insert(std::pair<Actor, int>(actor, minutos));
            }
            peliculas.emplace(peli, aux);
    }
}


void procesarEmisiones(RepartosPeliculas const& repartos, std::vector<std::string> const& secEmisiones) {
    // máximo número de veces que se ha emitido una película seguido de su título
    int i = 0, j = 0, aux = 0;
    std::vector<int> apariciones(secEmisiones.size());
    while (j < secEmisiones.size() && i < secEmisiones.size()) {
        aux = 0;
        Pelicula peli = secEmisiones[i];
        j = i;
        while (j != secEmisiones.size()) {
            if (secEmisiones[j] == peli) ++aux;
            ++j;
        }
        j = 0;
        apariciones[i] = aux;
        ++i;
    }

    i = 0; j = -1;
    int max = 0;
    while (i < apariciones.size()) {
        if (apariciones[i] >= j) { max = i; j = apariciones[i]; }
        ++i;
    }

    std::cout << apariciones[max] << " " << secEmisiones[max] << std::endl;

    // el máximo tiempo que ha aparecido un actor en pantalla seguido de los nombres 
    // de los actores que han aparecido ese tiempo máximo en orden alfabético.
    i = 0; j = 0; aux = 0;

    Reparto total;

    for (int e = 0; e < apariciones.size(); ++e) {
        Reparto repartoAux = repartos.find(secEmisiones[e])->second;
        for (auto it : repartoAux) {
            if (total.count(it.first)) total.find(it.first)->second += it.second;
            else {
                total.emplace(it);
            }
        }
    }

    int h = 0; int n = 0;

    Actor actor;

    for (auto it : total) {
        if (it.second > h) { n = it.second; actor = it.first; }
    }

    std::cout << n << " ";

    for (auto it : total) {
        if (it.second == n) std::cout << it.first << " ";
    }

    std::cout << std::endl;
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numPelis, numEmisiones;
    std::cin >> numPelis;
    if (numPelis == 0)
        return false;

    // Lectura de los repartos de las peliculas
    RepartosPeliculas repartos;
    leerRepartos(numPelis, repartos);

    // Lectura de la secuencia de peliculas emitidas en vector<string>
    std::cin >> numEmisiones;
    std::vector<std::string> secEmisiones(numEmisiones);
    for (std::string& s : secEmisiones) std::cin >> s;

    procesarEmisiones(repartos, secEmisiones);

    return true;
}


//#define DOMJUDGE
int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("input3.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    while (resuelveCaso())
        ;

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
#endif

    return 0;
}