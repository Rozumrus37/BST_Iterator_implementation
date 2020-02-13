#include <iostream>
#include "Tree.h"
#include "Node.h"

using namespace std;


int main() {
    srand (time(NULL));
    int n;
    cin >> n;
    int * a = new int[n];

    Node<int> * root = new Node<int> (rand() % 1000);
    Tree<int> * tree = new Tree<int>();

    for(int i = 1; i < n; i++) {
        a[i] = rand() % 1000;
        tree->insert(root, a[i]);
    }

    tree->past(root);

    tree->print_tree_with_iterator(tree);

    return 0;
}