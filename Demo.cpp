/**
 * Demo app for Ex4
 */

#include <iostream>
#include <string>
#include "Node.hpp"
#include "tree.hpp"
#include <SFML/Graphics.hpp>

using namespace std;

int main()
{

    Node<double> root_node{1.1};
    Tree<double> tree; // Binary tree that contains doubles.
    tree.add_root(root_node);

    Node<double> n1{1.2};
    Node<double> n2{1.3};
    Node<double> n3{1.4};
    Node<double> n4{1.5};
    Node<double> n5{1.6};
    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);
    std::cout << "\n";
    tree.draw();
    // The tree should look like:
    /**
     *       root = 1.1
     *     /       \
     *    1.2      1.3
     *   /  \      /
     *  1.4  1.5  1.6
     */

    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node)
    {
        if (node != tree.begin_pre_order())
            cout << ", ";
        cout << node->get_value();
    } // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6

    cout << "\n";

    for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node)
    {
        if (node != tree.begin_post_order())
            cout << ", ";
        cout << node->get_value();
    } // prints: 1.4, 1.5, 1.2, 1.6, 1.3, 1.1

    cout << "\n";

    for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node)
    {
        if (node != tree.begin_in_order())
            cout << ", ";
        cout << node->get_value();
    } // prints: 1.4, 1.2, 1.5, 1.1, 1.6, 1.3

    cout << "\n";

    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node)
    {
        if (node != tree.begin_bfs_scan())
            cout << ", ";
        cout << node->get_value();
    } // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6

    cout << "\n";

    for (auto node : tree)
    {

        if (node != tree.begin_bfs_scan()->get_value())
            cout << ", ";
        cout << node.get_value();
    } // same as BFS: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6

    // cout << tree; // Should print the graph using GUI.

    Tree<double, 3> three_ary_tree; // 3-ary tree.
    Node<double> root_node2{1.1};
    three_ary_tree.add_root(root_node2);
    three_ary_tree.add_sub_node(root_node2, n1);
    three_ary_tree.add_sub_node(root_node2, n2);
    three_ary_tree.add_sub_node(root_node2, n3);
    three_ary_tree.add_sub_node(n1, n4);
    three_ary_tree.add_sub_node(n2, n5);
    three_ary_tree.draw();
    // The tree should look like:
    /**
     *       root = 1.1
     *     /      |     \
     *    1.2    1.3    1.4
     *   /        |
     *  1.5      1.6
     */
    Tree<string> string_tree; // Binary tree that contains strings.
    Node<string> root_node3{"root"};
    string_tree.add_root(root_node3);
    Node<string> n6{"son1"};
    Node<string> n7{"son2"};
    Node<string> n8{"son3"};
    Node<string> n9{"son4"};
    string_tree.add_sub_node(root_node3, n6);
    string_tree.add_sub_node(root_node3, n7);
    string_tree.add_sub_node(n6, n8);
    string_tree.add_sub_node(n6, n9);
    string_tree.draw();
    return 0;
}
