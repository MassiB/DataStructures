/** @file CircularBuffer.hpp
 *  @brief Class definition of a circular buffer
 * 
 *  CircularBuffer class uses a linked list to
 *  define a buffer of a fixed size.
 * 
 *  @author Massinissa Bandou
 *  @bug No known bugs.
 */
#ifndef CIRCULARBUFFER_HPP_
#define CIRCULARBUFFER_HPP_

/***********************************************************
 *                   std includes
***********************************************************/
#include <iostream>

/***********************************************************
 *                 internal includes
***********************************************************/
#include "LinkedList.hpp"

template < typename T , const int size >
/** @class CircularBuffer
 *  @brief This class define a circular buffer of a fixed size
 */
class CircularBuffer final {
public:
    /***************************************************************************//**
    * @brief : Constructor
    *           
    * @param : none
    ******************************************************************************/
    CircularBuffer() = default;
    /***************************************************************************//**
    * @brief : Destructor
    *           
    * @param : none
    ******************************************************************************/
    ~CircularBuffer();
    /***************************************************************************//**
    * @brief : add an element to buffer
    *           
    * @param in : input - const T 
    ******************************************************************************/
    auto Put( const T input ) -> void;
    /***************************************************************************//**
    * @brief : remove an element to buffer
    *           
    * @param in : input - const T 
    ******************************************************************************/
    auto Remove( const T input ) -> void;
    /***************************************************************************//**
    * @brief : chevron operator
    * 
    * @param in  :  out : reference of std::ostream 
    *              CB  : CircularBuffer<T, size>
    * @param out : std::ostream&
    ******************************************************************************/
    friend auto operator << ( std::ostream &out, const CircularBuffer<T, size> &CB ) -> std::ostream& {
        out << CB.m_linkedList;
        return out;
    }

private:
    LinkedList<T> m_linkedList;
}; // class CircularBuffer

/***********************************************************
 *                Functions definition
************************************************************/
template < typename T, const int size>
CircularBuffer<T,size>::~CircularBuffer() {}

template < typename T, const int size >
auto CircularBuffer<T,size>::Put( const T input ) -> void {
    if (m_linkedList.Size() == size) {
        m_linkedList.PopFront();
    }
    m_linkedList.Add(input);
}

template < typename T, const int size >
auto CircularBuffer<T,size>::Remove( const T input ) -> void {
    m_linkedList.Remove(input);
}

#endif
