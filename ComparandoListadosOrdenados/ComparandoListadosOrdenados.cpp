// Ignacio Ligero Martín
// VJ26

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función auxiliar para añadir el resto de elementos del vector
void anadirRestantes(std::vector<std::string> const& rest, std::vector<std::string>& soloRest, const int k) {
    for (int l = k; l < rest.size(); ++l) {
        soloRest.push_back(rest[l]);
    }
}

// será lineal en el número de elementos del vector de mayor tamaño, 
// es decir, O(n)
void comparaListados(vector<string> const& eda, vector<string> const& tpv,
    vector<string>& comunes, vector<string>& soloEda, vector<string>& soloTpv) {

    int i = 0, j = 0;

    while (i < eda.size() && j < tpv.size()) {
        if (eda[i] < tpv[j]) { soloEda.push_back(eda[i]); ++i; }
        else if (eda[i] == tpv[j]) { comunes.push_back(eda[i]); ++i; ++j; }
        else { soloTpv.push_back(tpv[j]); ++j; }
    }

    if (i < eda.size()) anadirRestantes(eda, soloEda, i);
    else if (j < tpv.size()) anadirRestantes(tpv, soloTpv, j);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    vector<string> eda(n);
    vector<string> comunes;
    vector<string> soloEda;
    vector<string> soloTpv;
    for (string& e : eda) cin >> e;
    cin >> n;
    vector<string> tpv(n);
    for (string& e : tpv) cin >> e;
    comparaListados(eda, tpv, comunes, soloEda, soloTpv);
    for (string& e : comunes) cout << e << " ";
    cout << endl;
    for (string& e : soloEda) cout << e << " ";
    cout << endl;
    for (string& e : soloTpv) cout << e << " ";
    cout << endl;
}


//#define DOMJUDGE
int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
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
