#include <iostream>
#include <iomanip>
#include <fstream>
#include "list_eda.h"

template <class T>
class list_plus : public list<T> {
    using Nodo = typename list<T>::Nodo;
    using iterator = typename list<T>::iterator;

public:
    void resuelve() {
        iterator it = this->begin();
        iterator aux = it;
        if (it != this->end()) {
            ++it;
            for (it; it != this->end();) {
                if (*it < *aux)
                    it = this->erase(it);
                else { ++it; ++aux; }
            }
        }
    }
};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n, a;
    list_plus<int> q;
    std::cin >> n;
    while (n != -1) {
        q.push_back(n);
        std::cin >> n;
    }

    // llamada a metodo
    q.resuelve();

    // escribir sol (pero antes dar una vuelta para comprobar que la cola está bien formada)
    for (int i = 0; i < q.size(); ++i) {
        n = q.front();
        q.pop_front();
        q.push_back(n);
    }
    // Ahora imprimimos la cola y de paso la dejamos vacía
    while (!q.empty()) {
        std::cout << q.front() << " ";
        q.pop_front();
    }
    std::cout << std::endl;
}

//#define DOMJUDGE
int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    int casos;
    std::cin >> casos;
    for (int i = 0; i < casos; ++i) {
        resuelveCaso();
    }

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}
