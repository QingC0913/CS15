/*
 * BinarySearchTree.cpp
 * CS 15 HW3: Binary Search Trees
 * Spring 2021
 * 
 * edited by Qing Cheng
 * 11/16/2021 
 * 
 Every BST instance starts out empty, and the client can add and/or remove
 keys into the tree, as well as other operations.Duplicate keys in the BST 
 are kept track by the count variable in each node. When printing the tree, 
 an * next to a key denotes that the key contains duplicates. The public 
 functions call a corresponding recursive  private function to perform 
 the operation.
 */

#include <cstring>
#include <iostream>
#include <limits>

#include "BinarySearchTree.h"

using namespace std;
/*
BinarySearchTree
purpose: default constructor, initializes member vars
parameters: none 
*/
BinarySearchTree::BinarySearchTree()
{
    root = nullptr; 
}

/*
~BinarySearchTree
purpose: destructor
parameters: none
effects: frees allocated memory
*/
BinarySearchTree::~BinarySearchTree()
{
    // walk tree in post-order traversal and delete
    post_order_delete(root);
    root = nullptr;  // not really necessary, since the tree is going
                     // away, but might want to guard against someone
                     // using a pointer after deleting
}

/*
post_order_delete
purpose: removes all nodes from a tree and frees memory
parameters: a root node of BST tree to delete
returns: none
effects: all memory allocated by the BST will be freed
*/
void BinarySearchTree::post_order_delete(Node *node)
{
    if (node == nullptr)
            return; 
    post_order_delete(node->left); 
    post_order_delete(node->right); 
    delete node; 
}

/*
BinarySearchTree
purpose: copy constructor
parameters: a const ref var to another BST from which to copy 
effects: initializes a BST that's identical to a given BST 
*/
BinarySearchTree::BinarySearchTree(const BinarySearchTree &source)
{
    // use pre-order traversal to copy the tree
    root = pre_order_copy(source.root);
}

/*
operator = 
purpose: assignment overload
parameters: const ref var to another BST from which to copy
effects: deletes all existing nodes of current BST and copies all nodes 
        from the source BST to this tree
*/
BinarySearchTree &BinarySearchTree::operator=(const BinarySearchTree &source)
{
    // check for self-assignment
    if (this == &source)
        return *this; 

    // delete current tree if it exists
    else if (root != nullptr)
       post_order_delete(root); 
           
    // use pre-order traversal to copy the tree
    root = pre_order_copy(source.root); 
    
    return *this; 
}

/*
pre_order_copy
purpose: copies all nodes from a source BST to the current tree using
        pre-order traversal 
parameters: pointer to a node (in the source tree)
returns: pointer to the root of the newly copied tree
*/
BinarySearchTree::Node *BinarySearchTree::pre_order_copy(Node *node) const
{
    if (node == nullptr)
        return nullptr; 

    Node *copy = new Node; 
    copy->data = node->data; 
    copy->count = node->count; 

    copy->left = pre_order_copy(node->left); 
    copy->right = pre_order_copy(node->right); 
    return copy; 
}

/*
find_min() (public)
purpose: finds the min data value stored in a BST
parameters: none
returns: smallest data value stored in the BST
        if tree is empty, returns biggest possible int
effects: calls the private find_min()
*/
int BinarySearchTree::find_min() const
{
    if (root == nullptr)
        return numeric_limits<int>::max(); // INT_MAX

    return find_min(root)->data;
}

/*
find_min() (private)
purpose: finds the min data value stored in a BST
parameters: pointer to a node
returns: pointer to the node that contains the min data value
*/
BinarySearchTree::Node *BinarySearchTree::find_min(Node *node) const
{
    if (node == nullptr)
        return node; 
    //min value is on the most left node
    if (node->left == nullptr)    
        return node; 
    else
        return find_min(node->left);         
}

/*
find_max() (public)
purpose: finds the max data value stored in a BST
parameters: none
returns: biggest data value stored in the BST
        if tree is empty, returns smallest possible int
effects: calls the private find_max()
*/
int BinarySearchTree::find_max() const
{
    if (root == nullptr)
        return numeric_limits<int>::min(); // INT_MIN

    return find_max(root)->data;
}

/*
find_max() (private)
purpose: finds the max data value stored in a BST
parameters: pointer to a node
returns: pointer to the node that contains the max data value
*/
BinarySearchTree::Node *BinarySearchTree::find_max(Node *node) const
{
    if (node == nullptr)
        return node; 
    //min value is on the most left node
    if (node->right == nullptr)    
        return node; 
    else
        return find_max(node->right); 
}

/*
contains (public)
purpose: checks whether the BST contains a given data value
parameters: value being looked for
returns: true if value is found, false otherwise
effects: calls the private contains()
*/
bool BinarySearchTree::contains(int value) const
{
    return contains(root, value);    
}

/*
contains (private)
purpose: checks whether the BST contains a given data value using the 
        BST variant 
parameters: a pointer to a node, value being looked for
returns: true if value is found, false otherwise
*/
bool BinarySearchTree::contains(Node *node, int value) const
{
    if (node == nullptr)
        return false;    
    else if (node->data == value)
        return true;
        
    //use BST invariant to reduce # of recurs calls
    if (value < node->data)    
        return contains(node->left, value); 
        
    //for if value > node->data
    else    
        return contains(node->right, value); 

}

/*
insert (public)
purpose: adds a node to the BST with a given value
parameters: the value to be inserted
returns: none
effects: calls the private insert()
*/
void BinarySearchTree::insert(int value)
{
    root = insert(root, value);
}

/*
insert (private)
purpose: adds a node to the BST with a given value
parameters: a pointer to a node, the value to be inserted
returns: pointer to the node containing the root of the modified tree
effects: if tree was empty, after calling insert, tree will be non-empty
        (address stored in root pointer will be modified)
*/
BinarySearchTree::Node *BinarySearchTree::insert(Node *node, int value)
{
    if (node == nullptr)
    {
        node = newNode(value, nullptr, nullptr); 
        return node; 
    }
    //node with this key already exists
    else if (value == node->data)    
        node->count++; 
    else if (value < node->data)
        node->left = insert(node->left, value); 
    else if (value > node->data)
        node->right = insert(node->right, value); 
    return node; 
}

/*
newNode
purpose: allocates space for a new node 
parameters: value to be stored, pointers to the left and right children nodes
returns: pointer to the new node
effects: allocates space on the heap
*/
BinarySearchTree::Node *BinarySearchTree::newNode(int value, Node *left, 
                                                             Node *right)
{
    Node *new_node = new Node; 
    new_node->data = value; 
    new_node->count = 1; 
    new_node->left = left; 
    new_node->right = right; 
    
    return new_node; 
}

/*
remove (public)
purpose: decrements count of a node if dup exists, or remove node completely if
    there is no dup
parameters: an int value of the node to be removed 
returns: true if the node is removed successfully 
effects: calls private remove function
*/
bool BinarySearchTree::remove(int value)
{
    return remove(root, value);
}

/*
isLeaf
purpose: checks whether a given node is a leaf node 
parameters: pointer to a node 
returns: true if node is a leaf node, false otherwise
*/
bool BinarySearchTree::isLeaf(Node *node)
{
    if (node == nullptr)
        return false; 
    else if (node->left == nullptr and node->right == nullptr)
        return true; 
    return false; 
}

/*
rightMin 
purpose: replaces a node to be removed with the node with the min value in the
    right subtree 
parameters: pointer to a node 
returns: none 
effects: changes the left and/or right children pointers of some nodes, 
    removes the original node 
*/
void BinarySearchTree::rightMin(Node *node)
{
    Node *right_min = find_min(node->right);
    Node *right_min_parent = find_parent(root, right_min); 
 
    right_min->left = node->left; 
    right_min_parent->left = right_min->right;

    //node->right and right_min might point to the same node in some cases 
    //without this, will cause seg fault when following pointers because 
    //its right pointer would point to itself 
    if (node->right != right_min)
        right_min->right = node->right; 

    //make sures the to-be-removed node's parent points to the replacement node
    if (node != root)
    {
        Node *parent = find_parent(root, node); 
        if (node->data < parent->data)
            parent->left = right_min; 
        else
            parent->right = right_min;
    }
    else //can't use find_parent on root bc root has no parent :(
        root = right_min;
        
    delete node; 
}

/*
leftMax 
purpose: replaces a node to be removed with the node with the max value in the
    left subtree 
parameters: pointer to a node 
returns: none 
effects: changes the left and/or right children pointers of some nodes, 
    removes the original node 
*/
void BinarySearchTree::leftMax(Node *node)
{
    Node *left_max = find_max(node->left); 
    Node *left_max_parent = find_parent(root, left_max);
    
    left_max_parent->right = left_max->left; 
    
     //prevent having a node point to itself after rearranging pointers
    if (node->left != left_max)    
        left_max->left = node->left; 
        
    //left max is max, nothing else in this subtree is > it 
    left_max->right = nullptr;  
    
    //make sures the to-be-removed node's parent points to the replacement node
    if (node != root)
    {
        Node *parent = find_parent(root, node);
        if (node->data < parent->data)
            parent->left = left_max;
        else
            parent->right = left_max; 
    }
    else 
        root = left_max; 
       
    delete node; 
}

/*
removeHelper 
purpose: helper function for the remove function, called when node to be 
    removed is found; decrements count if the node has dup, removes the node 
    if the node has no dup
parameters: pointer to a node 
returns: true if node is removed, false otherwise 
effects: uses other helper functions to perform the operations 
*/
bool BinarySearchTree::removeHelper(Node *node)
{
    // there's just one node in tree
    if (node == root and node_count() == 1)  
    {
        delete root; 
        root = nullptr; 
    } 
    //if is a leaf 
    else if (isLeaf(node))  
    {
        Node *parent = find_parent(root, node); 
        if (node->data < parent->data)
            parent->left = nullptr; 
        else
            parent->right = nullptr; 
        delete node; 
    }
    //if has right subtree 
    else if (node->right != nullptr)  
        rightMin(node);     
        
    //if there is no right subtree
    else if (node->right == nullptr)  
        leftMax(node); 
    return true; 
}

/*
remove (private)
purpose: decrements count of a node if dup exists, or remove node completely if
    there is no dupparameters:
returns: true if node is removed, false otherwise 
*/
bool BinarySearchTree::remove(Node *node, int value)
{
    //node to remove doesn't exist, or is empty tree
    if (node == nullptr)    
        return false;    
        
    //found node to remove 
    else if (value == node->data)  
    {
        //if has dup, just decrease count
        if (node->count > 1)    
            node->count--;
            
        //no dup, have to remove node completely
        else      
            return removeHelper(node);
    }
    else if (value < node->data)
        return false or remove(node->left, value);
    else if (value > node->data)
        return false or remove(node->right, value); 

    return false;
}

/*
tree_height (publc)
purpose: finds maximum distance from the root to its farthest leaf
parameters: none
returns: height of the tree, 0 if tree only contains the root, -1 if empty tree
effects: calls the private tree_height
*/
int BinarySearchTree::tree_height() const
{
    return tree_height(root);
}

/*
tree_height (private)
purpose: measures height of a BST tree
parameters: pointer to a node
returns: height of the tree, 0 if tree only contains the root, -1 if empty tree
*/
int BinarySearchTree::tree_height(Node *node) const
{
    if (node == nullptr)
        return -1; 
    else 
    {
        return 1 + max(tree_height(node->left), 
                       tree_height(node->right));
    }
}

/*
node_count (public)
purpose: counts total number of distinct nodes in a BST
parameters: none
returns: int number of nodes
effects: calls the private node_count 
*/
int BinarySearchTree::node_count() const
{
    return node_count(root);
}

/*
node_count (private)
purpose: counts total number of distinct nodes in a BST
parameters: pointer to a node
returns: int number of nodes
*/
int BinarySearchTree::node_count(Node *node) const
{
    if (node == nullptr)
        return 0; 
    return 1 + node_count(node->left) + node_count(node->right);
}

/*
count_total (public)
purpose: finds sum of all the node values (including duplicates)
parameters: none
returns: the sum of all nodes' values
effects: calls the private count_total()
*/
int BinarySearchTree::count_total() const
{
    return count_total(root);
}

/*
count_total (private)
purpose: finds sum of all the node values (including duplicates)
parameters: pointer to a node
returns: the sum of all nodes' values
*/
int BinarySearchTree::count_total(Node *node) const
{
    if (node == nullptr) 
        return 0; 
    else
        return ((node->count) * node->data) + 
                    count_total(node->left) + count_total(node->right);
}

/*
find_parent (given)
purpose: finds parent node of a node
parameters: pointer to a node to start looking, pointer to the child node 
returns: pointer to the parent node of the given child 
*/
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

/*
print_tree (public) (given)
purpose: use the printPretty helper to make the tree look nice
parameters: none
returns: none
effects: calls the private print_tree()
*/
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

/*
print_tree (private) (given)
purpose: prints all nodes/values in the BST
parameters: pointer to a node, chars representing current position, 
line, and branch
returns: none
effects: prints tree to cout
*/
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
