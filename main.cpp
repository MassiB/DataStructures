/******************************
 *       std includes
*******************************/
#include <iostream>

/******************************
 *    internal includes
*******************************/
#include "DataStructures/LinkedList.hpp"
#include "DataStructures/CircularBuffer.hpp"

int main(int argc, char *argv[]) {
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
    //-------------------------//
    //    Circular Buffer      //
    //-------------------------//
    std::cout << "******** Circular Buffer ********" << std::endl;
    CircularBuffer<int,5> CB;
    CB.put(1);
    CB.put(2);
    CB.put(3);
    CB.put(4);
    CB.put(5);
    std::cout << CB << std::endl;
    CB.put(6);
    std::cout << CB << std::endl;


    return (0);
}