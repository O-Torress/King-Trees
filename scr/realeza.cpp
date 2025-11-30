#include "realeza.h"

// =====================
//      TREE
// =====================

Tree::Tree() : raiz(nullptr) {}

Node* Tree::getRoot() {
    return raiz;
}

void Tree::agregarRaiz(const string& nombre, int d, int m, int a) {
    raiz = new Node(nombre, d, m, a);
}

Node* Tree::buscar(Node* actual, const string& nombre) {
    if (!actual) return nullptr;
    if (actual->nombre == nombre) return actual;

    for (Node* h : actual->hijos) {
        Node* encontrado = buscar(h, nombre);
        if (encontrado) return encontrado;
    }
    return nullptr;
}

Node* Tree::buscar(const string& nombre) {
    return buscar(raiz, nombre);
}

void Tree::agregarHijo(const string& padre, const string& hijo, int d, int m, int a) {
    Node* p = buscar(padre);
    if (!p) {
        cout << "Padre no encontrado: " << padre << endl;
        return;
    }
    Node* nuevo = new Node(hijo, d, m, a);
    nuevo->padre = p;
    p->hijos.push_back(nuevo);
}

void Tree::imprimir(Node* actual, int nivel) {
    if (!actual) return;

    for (int i = 0; i < nivel; i++) cout << "  ";
    cout << "- " << actual->nombre << " (" << actual->dia << "/" << actual->mes << "/" << actual->anio << ")\n";

    for (Node* h : actual->hijos)
        imprimir(h, nivel + 1);
}

void Tree::imprimirArbol() {
    imprimir(raiz, 0);
}

Node* Tree::mayor(Node* actual) {
    if (!actual) return nullptr;
    Node* mayorTemp = actual;

    for (Node* h : actual->hijos) {
        Node* candidato = mayor(h);
        if (candidato &&
            (candidato->anio < mayorTemp->anio ||
             (candidato->anio == mayorTemp->anio && candidato->mes < mayorTemp->mes) ||
             (candidato->anio == mayorTemp->anio && candidato->mes == mayorTemp->mes && candidato->dia < mayorTemp->dia))) {
            mayorTemp = candidato;
        }
    }
    return mayorTemp;
}

// ===============================
//       SUCCESSION
// ===============================

bool Succession::esMayor(Node* a, Node* b) {
    if (!b) return true;
    if (!a) return false;

    if (a->anio != b->anio) return a->anio < b->anio;
    if (a->mes != b->mes) return a->mes < b->mes;
    return a->dia < b->dia;
}

Node* Succession::encontrarMayorPrioridad(Node* raiz) {
    if (!raiz) return nullptr;

    Node* mejor = raiz;
    queue<Node*> q;
    q.push(raiz);

    while (!q.empty()) {
        Node* actual = q.front();
        q.pop();

        if (esMayor(actual, mejor))
            mejor = actual;

        for (Node* h : actual->hijos)
            q.push(h);
    }
    return mejor;
}

void Succession::asignarRey(Tree& arbol) {
    Node* mayor = encontrarMayorPrioridad(arbol.getRoot());
    if (mayor)
        cout << "\n👑 El nuevo Rey es: " << mayor->nombre << "\n";
}

void Succession::mostrarLineaSucesion(Node* raiz) {
    cout << "\n➡ LINEA DE SUCESIÓN (BFS por antigüedad)\n";
    queue<Node*> q;
    q.push(raiz);

    while (!q.empty()) {
        Node* actual = q.front();
        q.pop();

        cout << "- " << actual->nombre << " (" << actual->dia << "/" << actual->mes << "/" << actual->anio << ")\n";

        for (Node* h : actual->hijos)
            q.push(h);
    }
}

// ===============================
//           CSV
// ===============================
void CSVHandler::cargarDatos(Tree& arbol, const string& ruta) {
    ifstream file(ruta);
    if (!file.is_open()) {
        cout << "Error al abrir CSV.\n";
        return;
    }

    string linea;
    getline(file, linea); // Saltar encabezado

    while (getline(file, linea)) {
        stringstream ss(linea);
        string padre, hijo, d, m, a;

        getline(ss, padre, ',');
        getline(ss, hijo, ',');
        getline(ss, d, ',');
        getline(ss, m, ',');
        getline(ss, a, ',');

        if (padre == "ROOT") {
            arbol.agregarRaiz(hijo, stoi(d), stoi(m), stoi(a));
        } else {
            arbol.agregarHijo(padre, hijo, stoi(d), stoi(m), stoi(a));
        }
    }
}
