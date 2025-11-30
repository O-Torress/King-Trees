#ifndef REALEZA_H
#define REALEZA_H

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <fstream>
#include <sstream>

using namespace std;

// =====================
//       NODO
// =====================
class Node {
public:
    string nombre;
    int dia, mes, anio;
    Node* padre;
    vector<Node*> hijos;

    Node(string n, int d, int m, int a)
        : nombre(n), dia(d), mes(m), anio(a), padre(nullptr) {}
};

// =====================
//       ÁRBOL
// =====================
class Tree {
private:
    Node* raiz;

public:
    Tree();
    Node* getRoot();
    Node* buscar(Node* actual, const string& nombre);
    Node* buscar(const string& nombre);

    void agregarHijo(const string& padre, const string& hijo, int d, int m, int a);
    void agregarRaiz(const string& nombre, int d, int m, int a);
    void imprimir(Node* actual, int nivel);
    void imprimirArbol();

    Node* mayor(Node* actual);
};

// ==============================
//  ALGORITMO DE SUCESIÓN
// ==============================
class Succession {
private:
    static bool esMayor(Node* a, Node* b);

public:
    static Node* encontrarMayorPrioridad(Node* raiz);
    static void asignarRey(Tree& arbol);
    static void mostrarLineaSucesion(Node* raiz);
};

// =====================
//       CSV
// =====================
class CSVHandler {
public:
    static void cargarDatos(Tree& arbol, const string& ruta);
};

#endif
