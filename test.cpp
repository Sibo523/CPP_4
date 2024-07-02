#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include <string>
#include "tree.hpp"
#include "Node.hpp"
#include "doctest.h"
#include "Iterators.hpp"
#include "Complex.hpp"
TEST_CASE("CHECK-ADD-ROOT")
{
    Tree<int> tree;
    Node<int> root_node{1};
    tree.add_root(root_node);
    CHECK(tree.get_root()->get_value() == 1);
}
TEST_CASE("check right degree")
{
    Tree<int> binary;
    Tree<int, 3> ternary;
    CHECK(binary.get_k() == 2);
    CHECK(ternary.get_k() == 3);
}
TEST_CASE("add sub root")
{
    Tree<int> tree;
    Node<int> root_node{1};
    tree.add_root(root_node);
    Node<int> n1{2};
    tree.add_sub_node(root_node, n1);
    CHECK(tree.get_root()->get_children().size() == 1);
    int num = tree.get_root()->get_children()[0]->get_value();
    CHECK(num == 2);
}
TEST_CASE("too much kids")
{
    Tree<int> tree;
    Node<int> root_node{1};
    tree.add_root(root_node);
    Node<int> n1{2};
    Node<int> n2{3};
    Node<int> n3{4};
    Node<int> n4{5};
    Node<int> n5{6};
    Node<int> n6{7};
    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    CHECK_THROWS_AS(tree.add_sub_node(root_node, n4), std::invalid_argument);
}

TEST_CASE("CHECK-ITERATORS")
{
    Tree<int> tree;
    Node<int> root_node{1};
    tree.add_root(root_node);
    Node<int> n1{2};
    Node<int> n2{3};
    Node<int> n3{4};
    Node<int> n4{5};
    Node<int> n5{6};
    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    SUBCASE("Pre-order")
    {
        std::string pre_order = "";
        for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node)
        {
            if (node != tree.begin_pre_order())
                pre_order += ", ";
            pre_order += std::to_string(node->get_value());
        }
        CHECK(pre_order == "1, 2, 4, 5, 3, 6");
    }
    SUBCASE("Post-order")
    {
        std::string post_order = "";
        for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node)
        {
            if (node != tree.begin_post_order())
                post_order += ", ";
            post_order += std::to_string(node->get_value());
        }
        CHECK(post_order == "4, 5, 2, 6, 3, 1");
    }
    SUBCASE("In-order")
    {
        std::string in_order = "";
        for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node)
        {
            if (node != tree.begin_in_order())
                in_order += ", ";
            in_order += std::to_string(node->get_value());
        }
        CHECK(in_order == "4, 2, 5, 1, 6, 3");
    }

    SUBCASE("BFS")
    {
        std::string bfs = "";
        for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node)
        {
            if (node != tree.begin_bfs_scan())
                bfs += ", ";
            bfs += std::to_string(node->get_value());
        }
        CHECK(bfs == "1, 2, 3, 4, 5, 6");
    }

    SUBCASE("DFS")
    {
        std::string dfs = "";
        for (auto node = tree.begin_dfs(); node != tree.end_dfs(); ++node)
        {
            if (node != tree.begin_dfs())
                dfs += ", ";
            dfs += std::to_string(node->get_value());
        }
        CHECK(dfs == "1, 2, 4, 5, 3, 6");
    }
    SUBCASE("heap")
    {
        std::string heap = "";
        for (auto node = tree.begin_heap(); node != tree.end_heap(); ++node)
        {
            if (node != tree.begin_heap())
                heap += ", ";
            heap += std::to_string(node->get_value());
        }
        CHECK(heap == "1, 3, 6, 2, 5, 4");
    }
}
TEST_CASE("Complex Numbers Operations")
{
    Complex a(1.0, 2.0);
    Complex b(3.0, 4.0);

    SUBCASE("Subtraction")
    {
        Complex result = a - b;
        CHECK(result.getReal() == -2.0);
        CHECK(result.getImag() == -2.0);
    }

    SUBCASE("Multiplication")
    {
        Complex result = a * b;
        CHECK(result.getReal() == -5.0);
        CHECK(result.getImag() == 10.0);
    }

    SUBCASE("Equality")
    {
        Complex c(1.0, 2.0);
        CHECK(a == c);
    }

    SUBCASE("Inequality")
    {
        CHECK(a != b);
    }

    SUBCASE("Assignment")
    {
        Complex c = a;
        CHECK(c.getReal() == 1.0);
        CHECK(c.getImag() == 2.0);
    }

    SUBCASE("Addition Assignment")
    {
        a += b;
        CHECK(a.getReal() == 4.0);
        CHECK(a.getImag() == 6.0);
    }

    SUBCASE("Subtraction Assignment")
    {
        a -= b;
        CHECK(a.getReal() == -2.0);
        CHECK(a.getImag() == -2.0);
    }

    SUBCASE("Multiplication Assignment")
    {
        a *= b;
        CHECK(a.getReal() == -5.0);
        CHECK(a.getImag() == 10.0);
    }
}
TEST_CASE("Complex_iterators")
{
    Tree<Complex> tree;
    Node<Complex> root_node{Complex(1.0, 2.0)};
    tree.add_root(root_node);
    Node<Complex> n1{Complex(3.0, 4.0)};
    Node<Complex> n2{Complex(5.0, 6.0)};
    Node<Complex> n3{Complex(7.0, 8.0)};
    Node<Complex> n4{Complex(9.0, 10.0)};
    Node<Complex> n5{Complex(11.0, 12.0)};
    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    SUBCASE("Pre-order")
    {
        std::string pre_order = "";
        for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node)
        {
            if (node != tree.begin_pre_order())
                pre_order += ", ";
            pre_order += std::to_string(static_cast<int>(std::floor(node->get_value().getReal()))) + "+" + std::to_string(static_cast<int>(std::floor(node->get_value().getImag()))) + "i";
        }
        CHECK(pre_order == "1+2i, 3+4i, 7+8i, 9+10i, 5+6i, 11+12i");
    }
    SUBCASE("Post-order")
    {
        std::string post_order = "";
        for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node)
        {
            if (node != tree.begin_post_order())
                post_order += ", ";
            post_order += std::to_string(static_cast<int>(node->get_value().getReal())) + "+" + std::to_string(static_cast<int>(node->get_value().getImag())) + "i";
        }
        CHECK(post_order == "7+8i, 9+10i, 3+4i, 11+12i, 5+6i, 1+2i");
    }
}