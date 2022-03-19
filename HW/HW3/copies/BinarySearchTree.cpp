/*
 * BinarySearchTree.cpp
 * COMP15
 * Spring 2021
 *
 * Implementation of the Binary Search Tree class.
 * Behaves like a standard BST except that it handles multiplicity
 * If you insert a number twice  and then remove it once, then it will
 * still be in the data structure
 */

#include <cstring>
#include <iostream>
#include <limits>

#include "BinarySearchTree.h"

using namespace std;

BinarySearchTree::BinarySearchTree()
{
        // TODO: Students write code here
}

BinarySearchTree::~BinarySearchTree()
{
        // walk tree in post-order traversal and delete
        post_order_delete(root);
        root = nullptr;  // not really necessary, since the tree is going
                         // away, but might want to guard against someone
                         // using a pointer after deleting
}

void BinarySearchTree::post_order_delete(Node *node)
{
        // TODO: students write code here
        // (hint: use a post-order traversal to remove all nodes)
}

// copy constructor
BinarySearchTree::BinarySearchTree(const BinarySearchTree &source)
{
        // use pre-order traversal to copy the tree
        root = pre_order_copy(source.root);
}

// assignment overload
BinarySearchTree &BinarySearchTree::operator=(const BinarySearchTree &source)
{
        // TODO: Students write code here
        // check for self-assignment

        // delete current tree if it exists

        // use pre-order traversal to copy the tree

        // don't forget to "return *this"
}

BinarySearchTree::Node *BinarySearchTree::pre_order_copy(Node *node) const
{
        // TODO: Students write code here
        // (hint: use a pre-order traversal to copy details from the
        // node to a new node)
}

int BinarySearchTree::find_min() const
{
        if (root == nullptr)
                return numeric_limits<int>::max(); // INT_MAX

        return find_min(root)->data;
}

BinarySearchTree::Node *BinarySearchTree::find_min(Node *node) const
{
        // TODO: Students write code here
}

int BinarySearchTree::find_max() const
{
        // TODO: Students write code here
}

BinarySearchTree::Node *BinarySearchTree::find_max(Node *node) const
{
        // TODO: Students write code here
}

bool BinarySearchTree::contains(int value) const
{
        // TODO: Students write code here
}

bool BinarySearchTree::contains(Node *node, int value) const
{
        // TODO: Students write code here
}
 
void BinarySearchTree::insert(int value)
{
        insert(root, nullptr, value);
}

void BinarySearchTree::insert(Node *node, Node *parent, int value)
{
        // TODO: Students write code here
}

bool BinarySearchTree::remove(int value)
{
        // TODO:  Students pick one of the following calls
        //        depending on which remove function they wrote
        //
        // return remove(root, nullptr, value);
        //
        // return remove(root, &root, value);
}

// TODO:  Students uncomment one of the following remove functions
//        and implement it.  You only have to do one, though if you
//        want to explore both, that's ok, but turn in the program
//        with one of them working!
//
// bool BinarySearchTree::remove(Node *node, Node *parent, int value)
// {
//         // TODO: Students write code here
//         // (cannot be a lazy removal)
// }

// bool BinarySearchTree::remove(Node *node, Node **ptr_to_ptr_to_me, int value)
// {
//         // TODO:  Students write code here
// }

int BinarySearchTree::tree_height() const
{
        return tree_height(root);
}

int BinarySearchTree::tree_height(Node *node) const
{
        // TODO: Students write code here
}

// returns the total number of nodes
int BinarySearchTree::node_count() const
{
        return node_count(root);
}

int BinarySearchTree::node_count(Node *node) const
{
        // TODO: Students write code here
}

// return the sum of all the node values (including duplicates)
int BinarySearchTree::count_total() const
{
        return count_total(root);
}

int BinarySearchTree::count_total(Node *node) const
{
        // TODO: Students write code here:
}

BinarySearchTree::Node *BinarySearchTree::find_parent(Node *node,
                                                      Node *child) const
{
        if (node == nullptr)
                return nullptr;

        // if either the left or right is equal to the child,
        // we have found the parent
        if (node->left == child or node->right == child) {
                return node;
        }

        // Use the binary search tree invariant to walk the tree
        if (child->data > node->data) {
                return find_parent(node->right, child);
        } else {
                return find_parent(node->left, child);
        }
}

// use the printPretty helper to make the tree look nice
void BinarySearchTree::print_tree() const
{
        size_t      numLayers  = tree_height() + 1;
        size_t      levelWidth = 4;
        const char *rootPrefix = "-> ";

        // Need numLayers * levelWidth characters for each layer of tree.
        // Add an extra levelWidth characters at front to avoid if statement
        // 1 extra char for nul character at end
        char *start = new char[(numLayers + 1) * levelWidth + 1];

        print_tree(root, start + levelWidth, start + levelWidth, rootPrefix);
        delete[] start;
}

// Logic and Output Reference: 
// https://www.techiedelight.com/c-program-print-binary-tree/
void BinarySearchTree::print_tree(Node *node, char *const currPos,
                                  const char *const fullLine,
                                  const char *const branch) const
{
        if (node == nullptr)
                return;

        // 4 characters + 1 for nul terminator
        using TreeLevel                    = char[5];
        static const int       levelLength = sizeof(TreeLevel) - 1;
        static const TreeLevel UP = ".-- ", DOWN = "`-- ", EMPTY = "    ",
                               CONNECT = "   |";
        // Copies prev into dest and advances dest by strlen(prev)
        auto set = [](char *dest, const char *prev) {
                size_t p = strlen(prev);
                return (char *)memcpy(dest, prev, p) + p;
        };

        print_tree(node->right, set(currPos, EMPTY), fullLine, UP);

        // Clear any characters that would immediate precede the "branch"
        // Don't need to check for root (i.e start of array),fullLine is padded
        set(currPos - levelLength, EMPTY);

        // Terminate fullLine at current level
        *currPos = '\0';

        std::cerr << fullLine << branch << node->data
                  << (node->count > 1 ? "*" : "") << endl;

        // Connect upper branch to parent
        if (branch == UP)
                set(currPos - levelLength, CONNECT);

        // Connect lower branch to parent
        print_tree(node->left, set(currPos, CONNECT), fullLine, DOWN);
}
