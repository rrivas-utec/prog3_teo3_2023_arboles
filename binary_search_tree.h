//
// Created by rrivas on 27/06/2023.
//

#ifndef PROG3_TEO3_2023_ARBOLES_BINARY_SEARCH_TREE_H
#define PROG3_TEO3_2023_ARBOLES_BINARY_SEARCH_TREE_H

#include <functional>
#include <memory>
using namespace std;

template <
        typename KeyType,
        typename ValueType,
        typename Compare= std::less<KeyType>
        >
class binary_search_tree {
    struct node_t {
        pair<KeyType, ValueType> item;
        shared_ptr<node_t> left;
        shared_ptr<node_t> right;
        weak_ptr<node_t> parent;
        node_t(pair<KeyType, ValueType> item, shared_ptr<node_t> parent):
            item(item), parent(parent) {}
    };

    shared_ptr<node_t> root;

public:
    binary_search_tree() = default;

};

#endif //PROG3_TEO3_2023_ARBOLES_BINARY_SEARCH_TREE_H
