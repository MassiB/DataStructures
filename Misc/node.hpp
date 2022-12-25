/** @file node.hpp
 *  @brief Function prototypes used by a linked list and a binary tree
 *
 *  This contains the prototypes for node and tree node creations
 *  used by a linkedlist and a binary tree.
 *
 *  @author Massinissa Bandou
 *  @bug No known bugs.
 */
#ifndef NODE_HPP_
#define NODE_HPP_

template < typename T > 
/** @struct Node
 *  @brief This structure is a node used by a doubly linked list
 *  @var Node::data
 *  Hold data value of the node
 *  @var Node::next* 
 *  Pointer to the next node
 *  @var Node::prev* 
 *  Pointer to the previous node
 */
struct Node final {
    Node<T>( const T _data, Node<T> *_next, Node<T> *_prev ) : 
        data(_data),
        next(_next),
        prev(_prev) {}
    
    T data {T(0)};
    Node<T> *next {nullptr}, *prev {nullptr};
}; // struct Node

template < typename T >
/** @struct TreeNode
 *  @brief This structure is a node used by binary tree
 *  @var TreeNode::data
 *  Hold data value of the node
 *  @var TreeNode::left* 
 *  Pointer to the left node
 *  @var TreeNode::right* git push --set-upstream origin BinaryTree
 *  Pointer to the right node
 */
struct TreeNode final {
    TreeNode ( const T _data, TreeNode<T> *_left, TreeNode<T> *_right ) :
        data(_data),
        left(_left),
        right(_right) {}
    
    T data {T(0)};
    TreeNode<T> *left {nullptr}, *right {nullptr};
}; // struct TreeNode

template < typename T > 
/** @brief : function to create a new node
 *  @param in  : data - data hold by a node
 *               next - pointer to next node
 *               prev - pointer to previous node
 *  @return : new Node
 */
auto createNewNode( const T data, 
                    Node<T> *next = nullptr, 
                    Node<T> *prev = nullptr ) -> Node<T>* {
    return new Node<T>(data, next, prev);
}

template < typename T >
/** @brief : function to free all attached nodes
 *  @param in  : node - Pointer to node
 *  @param out : none
 */
auto removeNodes( Node<T> *node ) -> void {
    auto n = node;
    while (nullptr != n){
        auto curr = n;
        n = n->next;
        if (nullptr != n)
            n->prev = nullptr;
        delete curr;
    }
}

template < typename T >
/** @brief : function to create a new tree node
 *  @param in  : data  - data hold by a tree node
 *               left  - pointer to left tree node
 *               right - pointer to right tree node
 *  @return : new TreeNode
 */
auto createNewTreeNode( const T data,
                        TreeNode<T> *left  = nullptr,
                        TreeNode<T> *right = nullptr ) -> TreeNode<T>* {
    return new TreeNode<T>(data, left, right);
}

template < typename T >
/** @brief : function to free all tree nodes
 *  @param in  : node - Pointer to tree node
 *  @param out : none
 */
auto removeTreeNode( TreeNode<T> *node ) -> void {
    if (nullptr != node){
        removeTreeNode(node->left);
        removeTreeNode(node->right);
        delete node;
    }
}

#endif
