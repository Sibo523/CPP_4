
#pragma once
#include <vector>
#include <iostream>
template <typename T>
class Node
{
public:
    Node(T t) : t(t) {}

    void addSon(Node<T> &son)
    {
        children.push_back(&son);
    }
    void clearChildren()
    {
        children.clear();
    }
    T get_value() const
    {
        return t;
    }
    const std::vector<Node<T> *> &get_children() const
    {
        return children;
    }
    size_t num_children() const
    {
        return children.size();
    }
    bool operator==(const Node<T> &other) const
    {
        return t == other.t;
    }
    bool operator!=(const Node<T> &other) const
    {
        return t != other.t;
    }
    bool operator<(const Node<T> &other) const
    {
        return t < other.t;
    }
    bool operator>(const Node<T> &other) const
    {
        return t > other.t;
    }

private:
    T t;
    std::vector<Node<T> *> children;
};
