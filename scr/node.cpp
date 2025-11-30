#include "node.hpp"

Node::Node()
    : id(0), name(""), last_name(""), gender('H'), age(0), id_father(0),
      is_dead(false), was_king(false), is_king(false), left(nullptr), right(nullptr) {}

Node::~Node() {
    // No liberamos hijos aquí — el administrador de memoria lo hará (Kingdom/Tree)
}
