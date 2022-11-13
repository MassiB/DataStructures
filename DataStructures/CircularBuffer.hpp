#ifndef CIRCULARBUFFER_HPP_
#define CIRCULARBUFFER_HPP_

/******************************
 *     std includes
*******************************/
#include <iostream>
/******************************
 *    internal includes
*******************************/
#include "LinkedList.hpp"

template < typename T , const int size>
class CircularBuffer final {
public:
    /***************************************************************************//**
    * Brief: Constructor
    *           
    * @param : none
    ******************************************************************************/
    CircularBuffer() {}
    /***************************************************************************//**
    * Brief: Destructor
    *           
    * @param : none
    ******************************************************************************/
    ~CircularBuffer() {}
    /***************************************************************************//**
    * Brief: add an element to buffer
    *           
    * @param : input : const T
    ******************************************************************************/
    auto put(const T input) -> void {
        if (m_linkedList.Size() == size) {
            m_linkedList.PopFront();
        }
        m_linkedList.Add(input);
    } 
    /***************************************************************************//**
    * Brief: chevron operator
    * 
    * @param :  out : std::ostream
    *           CB  : Circular Buffer
    ******************************************************************************/
    friend std::ostream& operator << (std::ostream &out, const CircularBuffer<T, size> &CB) {
        out << CB.m_linkedList;
        return out;
    }

private:
    LinkedList<T> m_linkedList;
}; // class CircularBuffer

#endif