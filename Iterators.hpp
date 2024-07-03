#pragma once
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
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
    ~inOrderIterator()
    {
        while (!stack.empty())
        {
            stack.pop();
        }
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
    ~preOrderIterator()
    {
        while (!stack.empty())
        {
            stack.pop();
        }
    }
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
    ~postOrderIterator()
    {
        while (!stack.empty())
        {
            stack.pop();
        }
        while (!temp_stack.empty())
        {
            temp_stack.pop();
        }
    }
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
    ~bfsIterator()
    {
        while (!queue.empty())
        {
            queue.pop();
        }
    }
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
    ~DfsIterator()
    {
        while (!stack.empty())
        {
            stack.pop();
        }
    }
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
// heapIterator class template for traversing trees in heap order.
template <typename T>
class heapIterator
{
public:
    // Destructor: Clears the heap to prevent memory leaks.
    ~heapIterator()
    {
        // Empties the heap vector by popping all elements.
        while (!heap.empty())
        {
            heap.pop_back();
        }
    }

    // Constructor: Initializes the iterator with the root node of a tree.
    heapIterator(Node<T> *root)
    {
        // If the root is null, set the current node to null and return.
        if (root == nullptr)
        {
            current = nullptr;
            return;
        }
        // Use a DFS iterator to populate the heap with all nodes in the tree.
        for (auto it = DfsIterator<T>(root); it != DfsIterator<T>(nullptr); ++it)
        {
            heap.push_back(&(*it));
        }
        // Convert the vector into a heap using the Compare functor.
        std::make_heap(heap.begin(), heap.end(), Compare());
        // Set the current node to the top of the heap if not empty.
        if (!heap.empty())
        {
            current = heap.front();
        }
    }

    // Prefix increment operator: Moves the iterator to the next node in heap order.
    heapIterator &operator++()
    {
        // If the heap is not empty, adjust the heap and set the current node.
        if (!heap.empty())
        {
            std::pop_heap(heap.begin(), heap.end(), Compare()); // Move the largest element to the end.
            heap.pop_back();                                    // Remove the largest element.
            // Update the current node to the new top of the heap, if not empty.
            if (!heap.empty())
            {
                current = heap.front();
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

    // Dereference operator: Returns a reference to the current node.
    Node<T> &operator*()
    {
        return *current;
    }

    // Inequality operator: Checks if two iterators are not equal based on their current nodes.
    bool operator!=(const heapIterator &other) const
    {
        return current != other.current;
    }

    // Arrow operator: Provides pointer access to the current node.
    Node<T> *operator->()
    {
        return current;
    }

private:
    // Compare functor for ordering nodes in the heap.
    struct Compare
    {
        // Defines the comparison criteria for the heap (e.g., based on node values).
        bool operator()(Node<T> *a, Node<T> *b) const
        {
            return *a > *b; // This needs to be defined according to the node comparison logic.
        }
    };

    std::vector<Node<T> *> heap; // Vector to store nodes in heap order.
    Node<T> *current = nullptr;  // Pointer to the current node in the iteration.
};