#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "queue_eda.h"


template <class T>
class queue_plus : public queue<T> {
    using Nodo = typename queue<T>::Nodo;

public:
    // tiene una eficiencia del tipo O(n), o mejor dicho, O(2n)
    void sort() {
        std::vector<T> auxPos, auxNeg; T ini;
        int size = queue<T>::size();

        for (int i = 0; i < size; ++i) {
            ini = queue<T>::front();
            if (ini < 0) { auxNeg.push_back(ini); }
            else auxPos.push_back(ini);
            queue<T>::pop();
        }

        for (int j = auxNeg.size() - 1; j >= 0; --j) {
            queue<T>::push(auxNeg[j]);
        }

        for (int k = 0; k < auxPos.size(); ++k) {
            queue<T>::push(auxPos[k]);
        }
    }
};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, a;
    queue_plus<int> q;
    std::cin >> n;
    if (n == 0) return false;
    for (int i = 0; i < n; ++i) {
        std::cin >> a;
        q.push(a);
    }

    // llamada a metodo
    q.sort();

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
