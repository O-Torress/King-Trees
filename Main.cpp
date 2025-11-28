#include <bits/stdc++.h>
using namespace std;

/*
  Proyecto: Sucesión real (árbol binario)
  Archivo: main.cpp
  Nota: poner este archivo en src/ y compilar con:
    g++ -std=c++17 src/main.cpp -o bin/reino
*/

struct Node {
    int id;
    string name;
    string last_name;
    char gender; // 'H' o 'M'
    int age;
    int id_father;
    bool is_dead;
    bool was_king;
    bool is_king;
    Node* left;  // primogénito
    Node* right; // segundo hijo

    Node() : id(0), gender('H'), age(0), id_father(0),
             is_dead(false), was_king(false), is_king(false),
             left(nullptr), right(nullptr) {}
};

class Kingdom {
private:
    unordered_map<int, Node*> nodes;
    Node* root; // primer rey (id_father == 0 o -1)
    string loaded_path;

public:
    Kingdom() : root(nullptr) {}

    ~Kingdom() {
        for (auto &p : nodes) delete p.second;
    }

    static vector<string> split_csv_line(const string &line) {
        vector<string> cols;
        string cur;
        bool in_quotes = false;
        for (size_t i = 0; i < line.size(); ++i) {
            char c = line[i];
            if (c == '"') {
                in_quotes = !in_quotes;
            } else if (c == ',' && !in_quotes) {
                cols.push_back(cur);
                cur.clear();
            } else {
                cur.push_back(c);
            }
        }
        cols.push_back(cur);
        return cols;
    }
};