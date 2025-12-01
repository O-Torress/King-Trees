#include "realeza.h"

int main() {
    Tree arbol;

    CSVHandler::cargarDatos(arbol, "../bin/realeza.csv");

    cout << "\n=== ÁRBOL GENEALÓGICO ===\n";
    arbol.imprimirArbol();

    Succession::asignarRey(arbol);

    Succession::mostrarLineaSucesion(arbol.getRoot());

    return 0;
}