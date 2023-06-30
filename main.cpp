#include <iostream>
#include "binary_search_tree.h"
using namespace std;

int main() {
    binary_search_tree<int, string> bst;
    bst.insert({40, "A"});
    bst.insert({10, "B"});
    bst.insert({50, "C"});
    bst.insert({60, "D"});
    bst.insert({30, "E"});
    bst.insert({20, "F"});
    bst.bfs([](const auto& item){
        cout << item.first << " " << item.second << endl;
    });
    cout << "---------------\n";
    bst.in_order([](const auto& item){
        cout << item.first << " " << item.second << endl;
    });
    return 0;
}
