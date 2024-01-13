/*
Nombre completo: Ignacio Ligero Martín
DNI:
Usuario del juez: VJ26
Puesto de laboratorio:
Qué has conseguido hacer y qué no:
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <unordered_map>
#include <map>
#include <list>

using namespace std;


class Fecha {
    int _dia, _mes, _anio;

public:
    Fecha(int d = 0, int m = 0, int a = 0) : _dia(d), _mes(m), _anio(a) {}
    int dia() const { return _dia; }
    int mes() const { return _mes; }
    int anio() const { return _anio; }
    bool operator<(Fecha const& other) const {
        return _anio < other._anio ||
            (_anio == other._anio && _mes < other._mes) ||
            (_anio == other._anio && _mes == other._mes && _dia < other._dia);
    }
};

inline std::istream& operator>>(std::istream& entrada, Fecha& h) {
    int d, m, a; char c;
    std::cin >> d >> c >> m >> c >> a;
    h = Fecha(d, m, a);
    return entrada;
}

inline std::ostream& operator<<(std::ostream& salida, Fecha const& f) {
    salida << std::setfill('0') << std::setw(2) << f.dia() << '/';
    salida << std::setfill('0') << std::setw(2) << f.mes() << '/';
    salida << std::setfill('0') << std::setw(2) << f.anio();
    return salida;
}

using Codigo = string;
using Cliente = string;

struct infoProd {
    int total;
    std::map<Fecha, int> fechaAdq;
};

using infoCliente = std::list<Cliente>;

class Tienda {
private:
    std::unordered_map<Codigo, infoProd> almacen;
    std::unordered_map<Codigo, infoCliente> listaEspera;
public:
    /// <summary>
    /// Gestiona la adquisición de cant unidades del producto cod con fecha f.
    /// Tiene coste O(k), siendo k el número de clientes en lista de espera.
    /// </summary>
    /// <param name="cod">Código del producto que se adquiere</param>
    /// <param name="f">Fecha de adquisición</param>
    /// <param name="cant">Cantidad del producto que se adquiere</param>
    /// <returns></returns>
    vector<Cliente> adquirir(Codigo const& cod, Fecha const& f, int cant) {
        auto itCliente = listaEspera.find(cod);
        auto itProd = almacen.find(cod);

        std::vector<Cliente> soluc; // vector solución

        // caso clientes pendientes de entrega (O(k), siendo k el número de clientes)
        if (itCliente != listaEspera.end()) {
            auto itPrioridad = itCliente->second.begin();

            int cantAsig = 0;

            for (int i = 0; i < cant && itPrioridad != itCliente->second.end(); ++i) {
                soluc.push_back(*itPrioridad);
                ++itPrioridad;
                ++cantAsig;
                itCliente->second.pop_front();
            }

            if (itCliente->second.empty()) listaEspera.erase(itCliente);

            int cantRest = cant - cantAsig;

            if (cantRest > 0) {
                if (itProd != almacen.end()) {
                    itProd->second.total += cantRest;
                    itProd->second.fechaAdq.insert({ f, cantRest });
                }
                else {
                    infoProd aux;
                    aux.total = cantRest;
                    aux.fechaAdq.insert({ f, cantRest });
                    almacen.insert({ cod, aux });
                }
            }
            // caso cant > listaEspera
            // caso cant == listaEspera
            // caso cant < listaEspera
        }

        // caso no hay clientes (O(1))
        else {
            if (itProd != almacen.end()) {
                itProd->second.total += cant;
                itProd->second.fechaAdq.insert({ f, cant });
            }
            else {
                infoProd aux;
                aux.total = cant;
                aux.fechaAdq.insert({ f, cant });
                almacen.insert({ cod, aux });
            }
        }

        return soluc;
    }

    /// <summary>
    /// Gestiona la venta de una unidad del producto cod al cliente cli.
    /// Tiene coste O(1).
    /// </summary>
    /// <param name="cod">Producto que se vende</param>
    /// <param name="cli">Cliente que compra</param>
    /// <returns></returns>
    pair<bool, Fecha> vender(Codigo const& cod, Cliente const& cli) {
        std::pair<bool, Fecha> soluc;
        auto itProd = almacen.find(cod);
        auto itCliente = listaEspera.find(cod);

        if (itProd != almacen.end() && itProd->second.total > 0) {
            soluc.first = true;
            auto itReciente = itProd->second.fechaAdq.begin();
            --itReciente->second;
            --itProd->second.total;
            soluc.second = itReciente->first;

            if (itReciente->second == 0) itProd->second.fechaAdq.erase(itReciente);
            // hay existencias
        }
        else {
            soluc.first = false;
            if (itCliente != listaEspera.end()) {
                itCliente->second.push_back(cli);
            }
            else {
                infoCliente aux;
                aux.push_back(cli);
                listaEspera.insert({ cod, aux });
            }
        }

        return soluc;
    }

    /// <summary>
    /// Devuelve cuántas unidades tiene la tienda del producto cod.
    /// Tiene coste O(1).
    /// </summary>
    /// <param name="cod">Producto que se quiere consultar</param>
    /// <returns>Unidades disponibles del producto</returns>
    int cuantos(Codigo const& cod) const {
        auto itProd = almacen.find(cod);

        if (itProd != almacen.end()) return itProd->second.total;
        else return 0;
    }

    /// <summary>
    /// Indica si hay clientes en la lista de espera del producto.
    /// Tiene coste O(1)
    /// </summary>
    /// <param name="cod">Producto a consultar</param>
    /// <returns>Existencia de clientes en espera para comprar</returns>
    bool hay_esperando(Codigo const& cod) const {
        auto itCliente = listaEspera.find(cod);

        return itCliente != listaEspera.end();
    }
};

bool resuelveCaso() {
    std::string operacion, cod, cli;
    Fecha f;
    int cant;
    std::cin >> operacion;
    if (!std::cin)
        return false;

    Tienda tienda;

    while (operacion != "FIN") {
        if (operacion == "adquirir") {
            cin >> cod >> f >> cant;
            vector<Cliente> clientes = tienda.adquirir(cod, f, cant);
            cout << "PRODUCTO ADQUIRIDO";
            for (auto c : clientes)
                cout << ' ' << c;
            cout << '\n';
        }
        else if (operacion == "vender") {
            cin >> cod >> cli;
            pair<bool, Fecha> venta = tienda.vender(cod, cli);
            if (venta.first) {
                cout << "VENDIDO " << venta.second << '\n';
            }
            else
                cout << "EN ESPERA\n";
        }
        else if (operacion == "cuantos") {
            cin >> cod;
            cout << tienda.cuantos(cod) << '\n';
        }
        else if (operacion == "hay_esperando") {
            cin >> cod;
            if (tienda.hay_esperando(cod))
                cout << "SI\n";
            else
                cout << "NO\n";
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