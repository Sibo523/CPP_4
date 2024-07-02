#pragma once
#include <stdexcept>
#include <iostream>
#include "Node.hpp"
#include "Iterators.hpp"
#include <SFML/Graphics.hpp>
#include <sstream>
#include <iomanip>

/**
 * @brief A generic tree data structure implementation.
 *
 * @tparam T The type of data stored in the tree.
 * @tparam k The maximum number of children each node can have. Default value is 2.
 */
template <typename T, int k = 2>
class Tree
{
public:
    Tree() : root(nullptr) {}
    ~Tree() = default;

    void draw()
    {
        sf::RenderWindow window(sf::VideoMode(800, 600), "Tree Visualization"); // Create a window
        while (window.isOpen())                                                 // While the window is open
        {
            sf::Event event;                // Create an event
            while (window.pollEvent(event)) // While there are events to process
            {
                if (event.type == sf::Event::Closed) // If the event is a close event, close the window
                    window.close();
            }

            window.clear(sf::Color::White);                      // Clear the window, set the background color to white
            sf::Font font;                                       // Create a font
            font.loadFromFile("fonts/arial.ttf");                // Load the font
            draw_help(window, root, 400, 50, 150, 100, 0, font); // calls the draw_help function to draw the tree

            window.display(); // Display the window
        }
    }

    /**
     * @brief Adds a root node to the tree.
     *
     * @param root The root node to be added.
     * @throw std::invalid_argument if the root has already been initialized.
     */
    void add_root(Node<T> &root)
    {
        if (this->root == nullptr) // check if the root has never been initialized
        {
            this->root = &root;
        }
        else
        {
            throw std::invalid_argument("Failed, root initialized before");
        }
    }

    /**
     * @brief Adds a child node to a parent node in the tree.
     *
     * @param parent The parent node.
     * @param son The child node to be added.
     * @throw std::invalid_argument if the parent already has k children.
     */
    void add_sub_node(Node<T> &parent, Node<T> &son)
    {
        if (parent.num_children() < k)
        {
            parent.addSon(son);
        }
        else
        {
            throw std::invalid_argument("Parent already has k children");
        }
    }

    /**
     * @brief Returns an iterator pointing to the beginning of the tree in pre-order traversal.
     *
     * @return preOrderIterator<T> An iterator pointing to the beginning of the tree in pre-order traversal.
     */
    preOrderIterator<T> begin_pre_order()
    {
        return preOrderIterator<T>(root);
    }

    /**
     * @brief Returns an iterator pointing to the end of the tree in pre-order traversal.
     *
     * @return preOrderIterator<T> An iterator pointing to the end of the tree in pre-order traversal.
     */
    preOrderIterator<T> end_pre_order()
    {
        return preOrderIterator<T>(nullptr);
    }

    /**
     * @brief Returns an iterator pointing to the beginning of the tree in post-order traversal.
     *
     * @return postOrderIterator<T> An iterator pointing to the beginning of the tree in post-order traversal.
     */
    postOrderIterator<T> begin_post_order()
    {
        return postOrderIterator<T>(root);
    }

    /**
     * @brief Returns an iterator pointing to the end of the tree in post-order traversal.
     *
     * @return postOrderIterator<T> An iterator pointing to the end of the tree in post-order traversal.
     */
    postOrderIterator<T> end_post_order()
    {
        return postOrderIterator<T>(nullptr);
    }

    /**
     * @brief Returns an iterator pointing to the beginning of the tree in in-order traversal.
     *
     * @return inOrderIterator<T> An iterator pointing to the beginning of the tree in in-order traversal.
     */
    inOrderIterator<T> begin_in_order()
    {
        return inOrderIterator<T>(root);
    }

    /**
     * @brief Returns an iterator pointing to the end of the tree in in-order traversal.
     *
     * @return inOrderIterator<T> An iterator pointing to the end of the tree in in-order traversal.
     */
    inOrderIterator<T> end_in_order()
    {
        return inOrderIterator<T>(nullptr);
    }

    /**
     * @brief Returns an iterator pointing to the beginning of the tree in breadth-first scan.
     *
     * @return bfsIterator<T> An iterator pointing to the beginning of the tree in breadth-first scan.
     */
    bfsIterator<T> begin_bfs_scan()
    {
        return bfsIterator<T>(root);
    }

    /**
     * @brief Returns an iterator pointing to the end of the tree in breadth-first scan.
     *
     * @return bfsIterator<T> An iterator pointing to the end of the tree in breadth-first scan.
     */
    bfsIterator<T> end_bfs_scan()
    {
        return bfsIterator<T>(nullptr);
    }

    /**
     * @brief Returns an iterator pointing to the beginning of the tree.
     *
     * @return bfsIterator<T> An iterator pointing to the beginning of the tree.
     */
    bfsIterator<T> begin()
    {
        return begin_bfs_scan();
    }

    /**
     * @brief Returns an iterator pointing to the end of the tree.
     *
     * @return bfsIterator<T> An iterator pointing to the end of the tree.
     */
    bfsIterator<T> end()
    {
        return end_bfs_scan();
    }
    DfsIterator<T> begin_dfs()
    {
        return DfsIterator<T>(root);
    }
    DfsIterator<T> end_dfs()
    {
        return DfsIterator<T>(nullptr);
    }
    heapIterator<T> begin_heap()
    {
        return heapIterator<T>(root);
    }
    heapIterator<T> end_heap()
    {
        return heapIterator<T>(nullptr);
    }
    Node<T> *get_root()
    {
        return root;
    }
    int get_k()
    {
        return k;
    }

private:
    Node<T> *root; // Pointer to the root node of the tree

    /**
     * @brief Helper function to draw the tree recursively.
     *
     * @param window The SFML window to draw on.
     * @param node The current node being drawn.
     * @param x The x-coordinate of the current node.
     * @param y The y-coordinate of the current node.
     * @param xOffset The horizontal offset between nodes.
     * @param yOffset The vertical offset between nodes.
     * @param depth The depth of the current node in the tree.
     */
    void draw_help(sf::RenderWindow &window, Node<T> *node, float x, float y, float xOffset, float yOffset, int depth, sf::Font font)
    {
        if (!node)
            return;

        // For each child
        for (size_t i = 0; i < node->get_children().size(); i++)
        {
            // Calculate child's position based on xOffset and yOffset
            float childX = x + (i - node->get_children().size() / 2.0) * xOffset;
            float childY = y + yOffset;

            // Draw line from current node to child
            sf::VertexArray lines(sf::Lines, 2);
            lines[0].position = sf::Vector2f(x, y);
            lines[1].position = sf::Vector2f(childX, childY);
            lines[0].color = sf::Color::Black;
            lines[1].color = sf::Color::Black;
            window.draw(lines);

            // Recursive call to draw child nodes
            draw_help(window, node->get_children()[i], childX, childY, xOffset / 2, yOffset, depth + 1, font);
        }

        // Draw current node (as a circle, for example)
        sf::CircleShape shape(20);         // Radius of 20
        shape.setPosition(x - 23, y - 18); // Adjust position
        shape.setFillColor(sf::Color::Cyan);
        window.draw(shape);

        // Create and draw text

        sf::Text text;
        text.setFont(font);
        std::string s = stringlize(node->get_value()); // made this because you can't to_string a string :( and didn't wanted to break to cases
        text.setString(s);                             // Use get_value() to access node value
        text.setCharacterSize(12);
        text.setFillColor(sf::Color::Black);
        text.setPosition(x, y);
        window.draw(text);
    }

    /**
     * @brief Converts a value to a string with a specified precision.
     *
     * @param t The value to be converted.
     * @param yepsilon The precision of the converted string. Default value is 5.
     * @return std::string The converted string.
     */
    std::string stringlize(T t, int yepsilon = 5)
    {
        std::stringstream ss;
        ss << std::fixed << std::setprecision(yepsilon) << t;
        return ss.str();
    }
};
