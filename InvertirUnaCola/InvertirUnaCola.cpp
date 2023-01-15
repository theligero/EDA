// Ignacio Ligero Martín
// VJ25


#include <iostream>
#include <iomanip>
#include <fstream>
#include "queue_eda.h"

template <class T>
class queue_plus : public queue<T> {
    using Nodo = typename queue<T>::Nodo;

public:
    void invierte() {
        Nodo* aux;
        Nodo* aux1 = nullptr;
        Nodo* aux2;

        aux = this->prim;
        this->prim = this->ult;
        this->ult = aux;

        while (aux != nullptr) {
            aux2 = aux->sig;
            aux->sig = aux1;
            aux1 = aux;
            aux = aux2;
        }
    }

    void imprime() const {
        Nodo* aux = this->prim;
        while (aux != nullptr) {
            std::cout << aux->elem << " ";
            aux = aux->sig;
        }
        std::cout << std::endl;
    }
};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int num;
    std::cin >> num;

    queue_plus<int> cola;

    if (!std::cin)
        return false;

    while (num != 0) {
        cola.push(num);
        std::cin >> num;
    }

    cola.invierte();

    cola.imprime();
    // escribir sol


    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}