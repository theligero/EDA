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
    // se trata de una función lineal del tipo O(n) ya que
    // se hace un recorrido por todo el vector independientemente
    // del número de elementos del mismo
    void duplica() {
        if (!this->empty()) {
            Nodo* aux = this->prim; 
            int cont = this->nelems;
            for (int i = 0; i < cont - 1; ++i) {
                Nodo* nodo = new Nodo(aux->elem, aux->sig);
                aux->sig = nodo;
                ++this->nelems;
                aux = nodo->sig;
            }
            Nodo* nodo = new Nodo(this->ult->elem);
            aux->sig = nodo;
            this->ult = nodo;
            ++this->nelems;
        }
    }
};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    queue_plus<int> q;
    std::cin >> n;
    if (!std::cin) return false;
    while (n != 0) {
        q.push(n);
        std::cin >> n;
    }

    // llamada a metodo
    q.duplica();

    // escribir sol (pero antes dar una vuelta para comprobar que la cola está bien formada)
    for (int i = 0; i < q.size(); ++i) {
        n = q.front();
        q.pop();
        q.push(n);
    }
    // Ahora imprimimos la cola y de paso la dejamos vacía
    while (!q.empty()) {
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << std::endl;
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

    while (resuelveCaso())
        ;

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}
