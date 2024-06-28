
#pragma once
#include <vector>

template <typename T>
class Node
{
public:
    Node(T t) : t(t) {}

    void addSon(Node<T> &son)
    {
        children.push_back(&son);
    }

    T get_value() const
    {
        return t;
    }

    size_t num_children() const
    {
        return children.size();
    }

private:
    T t;
    std::vector<Node<T> *> children;
};
