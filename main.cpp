/******************************
 *       std includes
*******************************/
#include <iostream>

/******************************
 *    internal includes
*******************************/
#include "DataStructures/LinkedList.hpp"

int main(int argc, char *argv[]) {
    //-------------------------//
    //      LinkedList         //
    //-------------------------//
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


    return (0);
}