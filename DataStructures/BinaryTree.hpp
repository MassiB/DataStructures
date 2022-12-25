/** @file BinaryTree.hpp
 *  @brief Class definition of a binary tree
 *
 *  @author Massinissa Bandou
 *  @bug No known bugs.
 */
#ifndef BINARYTREE_HPP_
#define BINARYTREE_HPP_

/***********************************************************
 *                 std includes
***********************************************************/
#include <iostream>

/***********************************************************
 *               internal includes
***********************************************************/
#include "../Misc/node.hpp" 
#include "../Misc/constants.hpp"
#include "LinkedList.hpp"

template < typename T >
/** @class BinaryTree
 *  @brief This class define a BinaryTree structure
 */
class BinaryTree final {
public:
    /***************************************************************************//**
    * @brief : Constructor
    *           
    * @param : none
    ******************************************************************************/
    BinaryTree() = default;
    /***************************************************************************//**
    * @brief : Desctructor
    *           
    * @param : none
    ******************************************************************************/
    ~BinaryTree();
    /***************************************************************************//**
    * @brief : Insert element to the binary tree
    *           
    * @param in: data  - data of T type
    ******************************************************************************/
    auto insert( const T data ) -> void;
    /***************************************************************************//**
    * @brief : Find the Tree Node that contains data
    *           
    * @param in : data  - data of T type
    * @return   : TreeNode<T>* - pointer to the node that contains data 
    ******************************************************************************/
    auto find( const T data ) -> TreeNode<T>*;
    /***************************************************************************//**
    * @brief : Delete all elements of the binary tree
    * 
    * @param - none
    ******************************************************************************/
    auto clear() -> void;
    /***************************************************************************//**
    * @brief : Get the lenght of the current tree
    * 
    * @param  - none
    * @return - lenght of the binary tree
    ******************************************************************************/
    auto lenght() -> std::size_t;
private:
    TreeNode<T> *root {nullptr};
    /***************************************************************************//**
    * @brief  : Insert element to the binary tree
    *           
    * @param in: data - const T
    * @param in: node - TreeNode<T> reference to a pointer
    ******************************************************************************/
    auto insert( const T data, TreeNode<T> **node ) -> void;
    /***************************************************************************//**
    * @brief  : Insert element to the binary tree
    *           
    * @param in: data - const T
    * @param out: TreeNode<T> - reference to a pointer to node containing data 
    ******************************************************************************/
    auto find( const T data, TreeNode<T> **node ) -> TreeNode<T>*;
    /***************************************************************************//**
    * @brief  : Return the lenght of the binary tree
    *           
    * @param in: TreeNode<T> - reference to a pointer to node containing data 
    * @return  : lenght of the binary tree
    ******************************************************************************/
    auto lenght( const TreeNode<T> *node ) -> std::size_t;
}; // class BinaryTree
/***********************************************************
 *                Functions definition
************************************************************/
template < typename T >
BinaryTree<T>::~BinaryTree() {
    clear();
}

template < typename T >
auto BinaryTree<T>::insert( const T data ) -> void {
    Insert(data, &root);
}

template < typename T >
auto BinaryTree<T>::insert( const T data, TreeNode<T> **node ) -> void {
    if (nullptr == *node) {
        (*node) = createNewTreeNode(data);
    } else {
        if ((*node)->data > data) {
            Insert(data, &((*node)->left)); 
        } else {
            Insert(data, &((*node)->right));
        }
    }
}

template < typename T >
auto BinaryTree<T>::find( const T data ) -> TreeNode<T>* {
    return find(data, &root);
}

template < typename T >
auto BinaryTree<T>::find( const T data, TreeNode<T> **node ) -> TreeNode<T>* {
    if (nullptr != *node) {
        if ((*node)->data == data) return *node;
        if ((*node)->data > data)  return find(data, &((*node)->left));
        else return find(data, &((*node)->right)); 
    }
    return nullptr;
}

template < typename T >
auto BinaryTree<T>::clear() -> void {
    removeTreeNode(root);
}

template < typename T >
auto BinaryTree<T>::lenght() -> std::size_t {
    return lenght(root);
}

template < typename T >
auto BinaryTree<T>::lenght( const TreeNode<T> *node ) -> std::size_t {
    int l = 0, r = 0;
    if ( nullptr != node ) {
        l = 1 + lenght(node->left);
        r = 1 + lenght(node->right);
    }
    return (l > r) ? l : r;
}

#endif
