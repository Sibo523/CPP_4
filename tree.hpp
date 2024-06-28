#pragma once
#include <stdexcept>
#include <iostream>
#include "Node.hpp"

template <typename T, int k = 2>
class Tree
{
public:
    Tree() : root(nullptr), k_arry(k) {}

    void add_root(Node<T> &root)
    {
        this->root = &root;
    }

    void add_sub_node(Node<T> &parent, Node<T> &son)
    {
        std::cout << parent.num_children() << std::endl;
        if (parent.num_children() > k_arry)
        {
            throw std::invalid_argument("Parent node is full");
        }
        parent.addSon(son);
    }
    void begin_pre_order()
    {
        return PreOrderIterator<T>(root);
    }
    viod end_pre_order()
    {
        return PreOrderIterator<T>(nullptr);
    }

private:
    Node<T> *root;
    size_t k_arry;
};

template <typename T>
class PreOrderIterator
{
public:
    PreOrderIterator(Node<T> *root) : root(root) {}
    Node<T> *begin()
    {
        return root;
    }
    Node<T> *end()
    {
        return nullptr;
    }
    Node<T> *operator++()
    {
        return nullptr;
    }

private:
    Node<T> *root;
};
