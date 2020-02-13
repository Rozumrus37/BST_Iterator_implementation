//
// Created by Ruslan Rozumnyi on 2/6/20.
//

#pragma once

template<typename T1>
struct Node {
    Node  *left;
    Node  *right;
    T1 value;
    Node(T1 value) {
        this->value = value;
        left = right = nullptr;
    };
};

