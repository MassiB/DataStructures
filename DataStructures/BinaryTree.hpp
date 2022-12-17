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
    * @param : data  - data of T type
    ******************************************************************************/
    auto Insert( const T data ) -> void;
    /***************************************************************************//**
    * @brief : chevron operator
    * 
    * @param :  out  -  reference to std::ostream
    *           BT   -  reference to BinaryTree
    ******************************************************************************/
    friend auto operator << ( std::ostream &out, const BinaryTree<T> &BT ) -> std::ostream& {
        int prev_level = 1, level = 1;
        LinkedList<std::pair<TreeNode<T>*, int>> ll;
        if ( nullptr != BT.root ) 
            ll.Add(std::make_pair(BT.root, level));

        while (!ll.Empty()){
            auto front = ll.Front();
            level = front.second;
            if ( prev_level != level ) {
                out << CONSOLE_OUTPUT_NEW_LINE;
                prev_level = level;
            }
            out << front.first->data << CONSOLE_OUTPUT_SPACING;
            if ( nullptr != front.first->left )
                ll.Add(std::make_pair(front.first->left, level + 1));
            if ( nullptr != front.first->right )
                ll.Add(std::make_pair(front.first->right, level + 1));
            ll.PopFront();
        }
        return out; 
    }

private:
    TreeNode<T> *root {nullptr};
    /***************************************************************************//**
    * @brief  : Insert element to the binary tree
    *           
    * @param : data - const T
    *          node - TreeNode<T>
    ******************************************************************************/
    auto Insert( const T data, TreeNode<T> **node ) -> void;
}; // class BinaryTree

/***********************************************************
 *                Functions definition
************************************************************/
template < typename T >
BinaryTree<T>::~BinaryTree() {
    removeTreeNode(root);
}

template < typename T >
auto BinaryTree<T>::Insert( const T data ) -> void {
    Insert(data, &root);
}

template < typename T >
auto BinaryTree<T>::Insert( const T data, TreeNode<T> **node ) -> void {
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

#endif
