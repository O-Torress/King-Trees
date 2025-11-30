#ifndef NODE_HPP
#define NODE_HPP

#include <string>

struct Node {
    int id;
    std::string name;
    std::string last_name;
    char gender; // 'H' o 'M'
    int age;
    int id_father;
    bool is_dead;
    bool was_king;
    bool is_king;
    Node* left;  // primogénito
    Node* right; // segundo hijo

    Node();
    ~Node();
};

#endif // NODE_HPP