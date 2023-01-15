// Ignacio Ligero Martín
// VJ25

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <climits>

bool esValida(std::vector<bool>const& haTocado, std::vector<std::vector<bool>> const& consentimientos,
    const int& pos, const int& prevArt) {
    if (prevArt == -1) return !haTocado[pos];
    else return !haTocado[pos] && consentimientos[pos][prevArt];
}

// función que resuelve el problema
void resolver(std::vector<std::vector<int>> const& beneficios, 
    std::vector<std::vector<bool>> const& consentimientos, std::vector<bool>& haTocado,
    int& ac, int& maxAc, int k, const int& m, int& prevArt) {
    for (int i = 0; i < m; ++i) {
        ac += beneficios[i][k];
        if (esValida(haTocado, consentimientos, i, prevArt)) {
            if (k == m - 1) {
                if (maxAc < ac) maxAc = ac;
            }
            else {
                int aux = prevArt;
                haTocado[i] = true;
                prevArt = i;
                resolver(beneficios, consentimientos, haTocado, ac, maxAc, k + 1, m, prevArt);
                prevArt = aux;
                haTocado[i] = false;
            }
        }
        ac -= beneficios[i][k];
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> beneficios(n, std::vector<int>(n));
    std::vector<std::vector<bool>> consentimientos(n, std::vector<bool>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            std::cin >> beneficios[i][j];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            int b;
            std::cin >> b;
            consentimientos[i][j] = b;
        }

    int ac = 0;
    int maxAc = INT_MIN;
    int prevArt = -1;
    std::vector<bool> orden(n, false);

    resolver(beneficios, consentimientos, orden, ac, maxAc, 0, n, prevArt);

    // salida
    if (maxAc == INT_MIN) std::cout << "NEGOCIA CON LOS ARTISTAS" << std::endl;
    else std::cout << maxAc << std::endl;
}

//#define DOMJUDGE
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
