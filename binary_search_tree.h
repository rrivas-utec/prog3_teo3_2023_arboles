//
// Created by rrivas on 27/06/2023.
//

#ifndef PROG3_TEO3_2023_ARBOLES_BINARY_SEARCH_TREE_H
#define PROG3_TEO3_2023_ARBOLES_BINARY_SEARCH_TREE_H

#include <functional>
#include <memory>
#include <queue>
using namespace std;

template <
        typename KeyType,
        typename ValueType,
        typename Compare= std::less<KeyType>
        >
class binary_search_tree {
    // Alias de tipos
    struct node_t;  // declaracion adelantada (forward)
    using item_t = pair<KeyType, ValueType>;
    using shared_ptr_t = shared_ptr<node_t>;
    using weak_ptr_t = weak_ptr<node_t>;

    struct node_t {
        item_t item;
        shared_ptr_t left;
        shared_ptr_t right;
        weak_ptr_t parent;
        node_t(item_t item, shared_ptr_t parent):
            item(item), parent(parent) {}
    };

    shared_ptr_t root;
    Compare cmp_fun;

    template<typename Callable>
    void _in_order(shared_ptr_t current, const Callable& fun) {
        // Si el arbol es vacio
        if (!current) return;
        // Ir al arbol izquierdo
        _in_order(current->left, fun);
        // Obtener el valor
        fun(current->item);
        // Ir al arbor derecho
        _in_order(current->right, fun);
    }

public:
    binary_search_tree() = default;

    void insert(const item_t& item) {
        if (!root) { // si no existe
            root = make_shared<node_t>(item, nullptr);
            return;
        }
        auto current = root;
        while(current) { // mientras existe
            if (cmp_fun(item.first, current->item.first)) {
                if (!current->left) {
                    current->left = make_shared<node_t>(item, current);
                    break;
                }
                else {
                    current = current->left;
                }
            }
            else {
                if (!current->right) {
                    current->right = make_shared<node_t>(item, current);
                    break;
                }
                else {
                    current = current->right;
                }
            }
        }
    }

    template<typename Callable>
    void bfs(const Callable& fun) {
        // Crear el queue
        queue<shared_ptr_t> q;
        // Realizar el push del root
        q.push(root);
        // Mientras el queue no este vacio
        while (!q.empty()) {
            // Obtener el front
            auto current = q.front();
            fun(current->item);
            // Extraer el front (pop)
            q.pop();
            // Agregar los hijos del nodo extraido
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
    }

    template<typename Callable>
    void in_order(const Callable& fun) {
        _in_order(root, fun);
    }
};

#endif //PROG3_TEO3_2023_ARBOLES_BINARY_SEARCH_TREE_H
