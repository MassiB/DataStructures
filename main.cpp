/** @file main.cpp
 *  @brief main thread 
 *          
 *  This main program executed simple display
 *  of using data structures such as Circular buffer
 *  Linked List and Binary Tree
 * 
 *  @author Massinissa Bandou
 *  @bug No known bugs.
 */

/******************************
*        std includes
*******************************/
#include <iostream>

/******************************
*     internal includes
*******************************/
#include "DataStructures/LinkedList.hpp"
#include "DataStructures/CircularBuffer.hpp"
#include "DataStructures/BinaryTree.hpp"

int main( int argc, char *argv[] ) {
    //-------------------------//
    //      LinkedList         //
    //-------------------------//
    std::cout << "********** LinkedList **********" << std::endl;
    LinkedList<int> ll;
    ll.Add(10);
    ll.Add(20);
    ll.Add(30);
    ll.Add(40);
    ll.Add(50);
    ll.Add(60);
    std::cout << ll << std::endl;
    ll.PopBack();
    std::cout << ll << std::endl;
    ll.PopFront();
    std::cout << ll << std::endl;
    ll.Remove(30);
    std::cout << ll << std::endl;
    ll.Clear();
    std::cout << ll << std::endl;
    //-------------------------//
    //    Circular Buffer      //
    //-------------------------//
    std::cout << "******** Circular Buffer ********" << std::endl;
    const int BufferSize = 5;
    CircularBuffer<int, BufferSize> CB;
    CB.Put(1);
    CB.Put(2);
    CB.Put(3);
    CB.Put(4);
    CB.Put(5);
    std::cout << CB << std::endl;
    CB.Put(6);
    std::cout << CB << std::endl;
    CB.Put(7);
    std::cout << CB << std::endl;
    CB.Put(8);
    std::cout << CB << std::endl;
    CB.Put(9);
    std::cout << CB << std::endl;
    CB.Put(10);
    std::cout << CB << std::endl;
    CB.Remove(6);
    std::cout << CB << std::endl;
    CB.Remove(7);
    std::cout << CB << std::endl;
    CB.Remove(8);
    std::cout << CB << std::endl;
    CB.Remove(9);
    std::cout << CB << std::endl;
    CB.Remove(10);
    std::cout << CB << std::endl;
    //-------------------------//
    //      Binray Tree        //
    //-------------------------//
    std::cout << "******** Binary Tree ********" << std::endl;
    BinaryTree<int> BT;
    BT.Insert(15);
    BT.Insert(10);
    BT.Insert(20);
    BT.Insert(17);
    BT.Insert(25);
    BT.Insert(7);
    BT.Insert(9);
    std::cout << BT << std::endl;

    return (0);
} // main
