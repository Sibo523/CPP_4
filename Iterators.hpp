#pragma once
#include <vector>
#include <queue>
#include <stack>
#include "Node.hpp"

template <typename T>
class inOrderIterator
{
public:
    inOrderIterator(Node<T> *root)
    {
        if (root == nullptr)
        {
            current = nullptr;
            return;
        }
        stack.push(root);
        while (stack.top()->get_children().size() > 0)
        {
            stack.push(stack.top()->get_children()[0]);
        }
        current = stack.top();
    }

    inOrderIterator &operator++()
    {
        if (!stack.empty())
        {
            Node<T> *node = stack.top();
            stack.pop();
            if (node->get_children().size() > 1)
            {
                stack.push(node->get_children()[1]);
                while (stack.top()->get_children().size() > 0)
                {
                    stack.push(stack.top()->get_children()[0]);
                }
            }
            if (!stack.empty())
            {
                current = stack.top();
            }
            else
            {
                current = nullptr;
            }
        }
        else
        {
            current = nullptr;
        }
        return *this;
    }

    Node<T> &operator*()
    {
        return *current;
    }

    bool operator!=(const inOrderIterator &other) const
    {
        return current != other.current;
    }

    Node<T> *operator->()
    {
        return current;
    }

private:
    std::stack<Node<T> *> stack;
    Node<T> *current;
};

// Pre-order iterator for k-ary tree
template <typename T>
class preOrderIterator
{
public:
    preOrderIterator(Node<T> *root)
    {
        if (root == nullptr)
        {
            current = nullptr;
            return;
        }
        stack.push(root);
        current = stack.top();
    }

    preOrderIterator &operator++()
    {
        if (!stack.empty())
        {
            current = stack.top();
            stack.pop();
            std::vector<Node<T> *> children = current->get_children();
            for (auto it = children.rbegin(); it != children.rend(); ++it)
            {
                stack.push(*it);
            }
            if (!stack.empty())
            {
                current = stack.top();
            }
            else
            {
                current = nullptr;
            }
        }
        else
        {
            current = nullptr;
        }
        return *this;
    }

    Node<T> &operator*()
    {
        return *current;
    }

    bool operator!=(const preOrderIterator &other) const
    {
        return current != other.current;
    }

    Node<T> *operator->()
    {
        return current;
    }

private:
    std::stack<Node<T> *> stack;
    Node<T> *current;
};

// Post-order iterator for k-ary tree
template <typename T>
class postOrderIterator
{
public:
    postOrderIterator(Node<T> *root)
    {
        if (root == nullptr)
        {
            current = nullptr;
            return;
        }
        stack.push(root);
        while (!stack.empty())
        {
            Node<T> *node = stack.top();
            stack.pop();
            temp_stack.push(node);
            for (auto child : node->get_children())
            {
                stack.push(child);
            }
        }
        current = temp_stack.top();
        temp_stack.pop();
    }

    postOrderIterator &operator++()
    {
        if (!temp_stack.empty())
        {
            current = temp_stack.top();
            temp_stack.pop();
        }
        else
        {
            current = nullptr;
        }
        return *this;
    }

    Node<T> &operator*()
    {
        return *current;
    }

    bool operator!=(const postOrderIterator &other) const
    {
        return current != other.current;
    }

    Node<T> *operator->()
    {
        return current;
    }

private:
    std::stack<Node<T> *> stack;
    std::stack<Node<T> *> temp_stack;
    Node<T> *current;
};

// BFS iterator for k-ary tree
template <typename T>
class bfsIterator
{
public:
    bfsIterator(Node<T> *root)
    {
        if (root == nullptr)
        {
            current = nullptr;
            return;
        }
        queue.push(root);
        current = queue.front();
    }

    bfsIterator &operator++()
    {
        if (!queue.empty())
        {
            current = queue.front();
            queue.pop();
            for (auto child : current->get_children())
            {
                queue.push(child);
            }
            if (!queue.empty())
            {
                current = queue.front();
            }
            else
            {
                current = nullptr;
            }
        }
        else
        {
            current = nullptr;
        }
        return *this;
    }

    Node<T> &operator*()
    {
        return *current;
    }

    bool operator!=(const bfsIterator &other) const
    {
        return current != other.current;
    }

    Node<T> *operator->()
    {
        return current;
    }

private:
    std::queue<Node<T> *> queue;
    Node<T> *current;
};

// DFS iterator for k-ary tree
template <typename T>
class DfsIterator
{
public:
    DfsIterator(Node<T> *root)
    {
        if (root == nullptr)
        {
            current = nullptr;
            return;
        }
        stack.push(root);
        current = stack.top();
    }

    DfsIterator &operator++()
    {
        if (!stack.empty())
        {
            current = stack.top();
            stack.pop();
            std::vector<Node<T> *> children = current->get_children();
            for (auto it = children.rbegin(); it != children.rend(); ++it)
            {
                stack.push(*it);
            }
            if (!stack.empty())
            {
                current = stack.top();
            }
            else
            {
                current = nullptr;
            }
        }
        else
        {
            current = nullptr;
        }
        return *this;
    }

    Node<T> &operator*()
    {
        return *current;
    }

    bool operator!=(const DfsIterator &other) const
    {
        return current != other.current;
    }

    Node<T> *operator->()
    {
        return current;
    }

private:
    std::stack<Node<T> *> stack;
    Node<T> *current;
};

template <typename T>
class heapIterator
{
public:
    heapIterator(Node<T> *root)
    {
        if (root == nullptr)
        {
            current = nullptr;
            return;
        }
        queue.push(root);
        current = queue.front();
    }

    heapIterator &operator++()
    {
        if (!queue.empty())
        {
            current = queue.front();
            queue.pop();
            for (auto child : current->get_children())
            {
                queue.push(child);
            }
            if (!queue.empty())
            {
                current = queue.front();
            }
            else
            {
                current = nullptr;
            }
        }
        else
        {
            current = nullptr;
        }
        return *this;
    }

    Node<T> &operator*()
    {
        return *current;
    }

    bool operator!=(const heapIterator &other) const
    {
        return current != other.current;
    }

    Node<T> *operator->()
    {
        return current;
    }

private:
    std::priority_queue<Node<T> *> queue;
    Node<T> *current;
};