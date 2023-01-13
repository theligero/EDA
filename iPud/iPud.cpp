// Ignacio Ligero Martín
// VJ25

#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <stdexcept>
#include <list>
#include <unordered_map>

using cancion = std::string;
using artista = std::string;

class iPud {
private:
    struct infoCancion {
        artista art;
        int dur;
        bool enLista = false;
        bool escuchada = false;
        std::list<cancion>::iterator posLista;
        std::list<cancion>::iterator posEscucha;
    };
    std::unordered_map<cancion, infoCancion> canciones;
    std::list<cancion> listaRepro;
    std::list<cancion> escuchadas;
    int durLista = 0;
public:
    // O(1)
    void addSong(const cancion& S, const artista& A, const int& D) {
        auto it = canciones.find(S);
        if (it == canciones.cend()) {
            infoCancion aux;
            aux.art = A; aux.dur = D;
            canciones[S] = aux;
        }
        else throw std::invalid_argument("addSong");
    }
    // O(1)
    void addToPlaylist(const cancion& S) {
        auto it = canciones.find(S);
        if (it != canciones.cend()) {
            if (!it->second.enLista) {
                listaRepro.push_back(S);
                auto it2 = listaRepro.end();
                --it2;
                it->second.posLista = it2;
                it->second.enLista = true;
                durLista += it->second.dur;
            }
        }
        else throw std::invalid_argument("addToPlaylist");
    }
    // O(1)
    cancion current() {
        if (!listaRepro.empty())
            return listaRepro.front();
        else throw std::invalid_argument("current");
    }
    // O(1)
    void play() {
        if (!listaRepro.empty()) {
            if (canciones[listaRepro.front()].escuchada) {
                escuchadas.erase(canciones[listaRepro.front()].posEscucha);
            }
            escuchadas.emplace_front(listaRepro.front());
            canciones[listaRepro.front()].posEscucha = escuchadas.begin();
            canciones[listaRepro.front()].enLista = false;
            durLista -= canciones[listaRepro.front()].dur;
            canciones[listaRepro.front()].escuchada = true;
            listaRepro.pop_front();
        }
    }
    // O(1)
    int totalTime() {
        return durLista;
    }
    // O(N)
    std::list<cancion> recent(const int& N) {
        std::list<cancion> aux;
        int ac = 0;
        for (auto it = escuchadas.cbegin(); it != escuchadas.cend() && ac < N; ++it) {
            aux.emplace_back(*it);
            ++ac;
        }
        return aux;
    }
    // O(1)
    void deleteSong(const cancion& S) {
        auto it = canciones.find(S);
        if (it != canciones.cend()) {
            if (it->second.enLista) {
                listaRepro.erase(it->second.posLista);
                durLista -= it->second.dur;
            }
            if (it->second.escuchada)
                escuchadas.erase(it->second.posEscucha);
            canciones.erase(it);
        }
    }
};


bool resuelve() {
    std::string operacion;
    std::cin >> operacion;
    if (!std::cin)
        return false;
    cancion tit; artista aut; int dur;
    iPud ipud;
    while (operacion != "FIN") {
        try {
            if (operacion == "addSong") {
                std::cin >> tit >> aut >> dur;
                ipud.addSong(tit, aut, dur);
            }
            else if (operacion == "addToPlaylist") {
                std::cin >> tit;
                ipud.addToPlaylist(tit);
            }
            else if (operacion == "current") {
                tit = ipud.current(); // aunque no se hace nada, puede producir error
            }
            else if (operacion == "play") {
                try {
                    std::string tocando = ipud.current(); // para saber si la lista es vacía
                    ipud.play();
                    std::cout << "Sonando " << tocando << '\n';
                }
                catch (std::invalid_argument e) {
                    std::cout << "No hay canciones en la lista\n";
                }
            }
            else if (operacion == "totalTime") {
                std::cout << "Tiempo total " << ipud.totalTime() << '\n';
            }
            else if (operacion == "recent") {
                int N;
                std::cin >> N;
                auto lista = ipud.recent(N);
                if (lista.empty())
                    std::cout << "No hay canciones recientes\n";
                else {
                    std::cout << "Las " << lista.size() << " mas recientes\n";
                    for (auto const& s : lista)
                        std::cout << "    " << s << '\n';
                }
            }
            else if (operacion == "deleteSong") {
                std::cin >> tit;
                ipud.deleteSong(tit);
            }
            else { // operacion desconocida
                assert(false);
            }
        }
        catch (std::invalid_argument e) {
            std::cout << "ERROR " << e.what() << '\n';
        }
        std::cin >> operacion;
    }
    std::cout << "---\n";
    return true;
}

//#define DOMJUDGE
int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    while (resuelve())
        ;

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
#endif

    return 0;
}
