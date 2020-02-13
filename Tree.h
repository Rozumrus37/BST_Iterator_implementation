//
// Created by Ruslan Rozumnyi on 2/6/20.
//

#pragma once

#include <iostream>
#include <stack>
#include "Node.h"

using namespace std;

template<class T>
class Tree {
private:
    stack<Node<T> * > q;
public:
    //////iterator implementation
    void past(Node<T> * root) {
        Node<T> * curr = root;
        while(curr != nullptr)
            q.push(curr), curr = curr->left;
    }

    Node<T> * curr() {
        if(!q.empty())
            return q.top();
        return nullptr;
    }

    void next() {
        Node<T> * curr = q.top()->right;
        q.pop();
        while(curr != nullptr)
            q.push(curr), curr = curr->left;
    }
    bool tree_empty() {
        return !(q.size());
    }
    void print_tree_with_iterator(Tree * bst) {
        while(!tree_empty()) {
            cout << bst->curr()->value << " ", bst->next();
        }

    }
//////////////////////


    void insert(Node<T> *root, T val) {
        if (root->value > val) {
            if (!root->left) {
                root->left = new Node<T>(val);
            } else {
                insert(root->left, val);
            }
        } else {
            if (!root->right) {
                root->right = new Node<T>(val);
            } else {
                insert(root->right, val);
            }
        }
    }

    void print(Node<T> *root) {
        if (!root) return;
        print(root->left);
        std::cout << root->value << " ";
        print(root->right);
    }

    bool find(Node<T> *root, T val) {
        if(root == nullptr) return 0;
        if(root->value == val) return 1;
        if(find(root->left, val)) return 1;
        return find(root->right, val);
    }

    T find_min(Node<T> *root) {
        if(root->left == nullptr)
            return root->value;
        return find_min(root->left);

    }

    T find_max(Node<T> *root) {
        if (root->right == nullptr)
            return root->value;
        return find_max(root->right);
    }


};
