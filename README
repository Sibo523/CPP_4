# Tree Visualization and Traversal Library

This library offers a robust framework for visualizing and traversing k-ary trees through various traversal techniques, leveraging C++ and the SFML library for graphical representations.

## Features

### Tree Visualization
Utilizes SFML to render the tree structure within a window, offering a clear visual representation of the tree.

### Root Management
Supports the addition of a root node to the tree, incorporating error management for attempts to add multiple roots.

### Node Management
Enables the addition of child nodes to a parent node, including safeguards against surpassing the maximum child count (k).

### Traversal Iterators
Includes iterators designed for different traversal strategies:
- Pre-order
- Post-order
- In-order (specifically for binary trees)
- Breadth-First Search (BFS)
- Depth-First Search (DFS)
- Heap Order (employing a priority queue)

## Usage

### Tree Operations

#### Adding a Root Node
Create and add a root node to the tree. An exception will be thrown if a root already exists.

#### Adding Child Nodes
Add child nodes to a specified parent node. An exception is triggered if the parent node already reaches its maximum number of children (k).

### Visualization

#### Drawing the Tree
Invoke the draw method on a tree object to launch a window displaying the tree structure.

### Traversal

#### Iterators
Employ the iterators provided to traverse the tree according to your preferred order. Each iterator facilitates increment operations and comparison for iteration control.

## Example
// Add child nodes
Node<int>* childNode1 = myTree.addChild(rootNode, 2);
Node<int>* childNode2 = myTree.addChild(rootNode, 3);

// Traverse using BFS
BFSIterator<int> bfs(myTree.getRoot());
while (!bfs.isDone()) {
    std::cout << bfs.currentItem() << " ";
    bfs.next();
}

return 0;
}

## Dependencies

- SFML (Simple and Fast Multimedia Library) for visualization purposes.
- C++17 or higher for template and STL functionalities.

## Installation

Ensure SFML is installed on your system. Include `Tree.hpp` and `Iterators.hpp` files in your project. Compile your project with C++17 support enabled.

Enjoy exploring and manipulating trees with this comprehensive library!

