#pragma once
#include <stdexcept>
#include <iostream>
#include "Node.hpp"
#include "Iterators.hpp"

template <typename T, int k = 2>
class Tree
{
public:
    Tree() : root(nullptr) {}

    void add_root(Node<T> &root)
    {
        if (this->root == nullptr) // check if the root never been intilized
        {
            this->root = &root;
        }
        else
        {
            throw std::invalid_argument("failed, root intilized before");
        }
    }

    void add_sub_node(Node<T> &parent, Node<T> &son)
    {
        // std::cout << parent.num_children() << std::endl;
        if (parent.num_children() < k)
        {

            parent.addSon(son);
        }
        else
        {
            throw std::invalid_argument("Parent already has k children");
        }
    }

    preOrderIterator<T> begin_pre_order()
    {
        return preOrderIterator<T>(root);
    }
    preOrderIterator<T> end_pre_order()
    {
        return preOrderIterator<T>(nullptr);
    }
    postOrderIterator<T> begin_post_order()
    {
        return postOrderIterator<T>(root);
    }
    postOrderIterator<T> end_post_order()
    {
        return postOrderIterator<T>(nullptr);
    }
    inOrderIterator<T> begin_in_order()
    {
        return inOrderIterator<T>(root);
    }
    inOrderIterator<T> end_in_order()
    {
        return inOrderIterator<T>(nullptr);
    }
    bfsIterator<T> begin_bfs_scan()
    {
        return bfsIterator<T>(root);
    }
    bfsIterator<T> end_bfs_scan()
    {
        return bfsIterator<T>(nullptr);
    }
    bfsIterator<T> begin()
    {
        return begin_bfs_scan();
    }
    bfsIterator<T> end()
    {
        return end_bfs_scan();
    }

private:
    Node<T> *root;
};
