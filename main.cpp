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
#include <list>

/******************************
*     internal includes
*******************************/
#include "DataStructures/LinkedList.hpp"
#include "DataStructures/CircularBuffer.hpp"
#include "DataStructures/BinaryTree.hpp"
#include "DataStructures/Graph.hpp"

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
    //-------------------------//
    //         Graph           //
    //-------------------------//
    std::cout << "*********** Graph ************" << std::endl;
    const int vertices = 4;
    std::list<EDGE<int>> l;
    EDGE<int> edg0(1,2);
    EDGE<int> edg1(2,3);
    EDGE<int> edg2(3,4);
    EDGE<int> edg3(4,1);
    EDGE<int> edg4(2,4);
    l.push_back(edg0);
    l.push_back(edg1);
    l.push_back(edg2);
    l.push_back(edg3);
    l.push_back(edg4);
    Graph<int> graph(vertices);
    graph.Add(l);
    std::cout << graph << std::endl;

    return (0);
} // main
