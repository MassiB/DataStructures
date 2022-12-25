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

template < typename T , std::size_t size >
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
    ~CircularBuffer() = default;
    /***************************************************************************//**
    * @brief : add an element to buffer
    *           
    * @param in : input - const T 
    ******************************************************************************/
    auto put( const T input ) -> void;
    /***************************************************************************//**
    * @brief : Remove an element to buffer
    *           
    * @param in : input - const T 
    ******************************************************************************/
    auto remove( const T input ) -> void;
    /***************************************************************************//**
    * @brief : Remove all elements in current buffer
    *           
    * @param : none
    ******************************************************************************/
    auto removeAll() -> void;
    /***************************************************************************//**
    * @brief : Verify if circular buffer is empty or not
    *           
    * @param  : none
    * @return : Return true if circular buffer is empty
    ******************************************************************************/
    auto empty() -> bool;
    /***************************************************************************//**
    * @brief : Index operator
    * 
    * @param in:  index position
    * @return  :  Reference to data at position index  
    ******************************************************************************/
    auto operator[] ( const std::size_t index ) -> T&;
private:
    LinkedList<T> m_linkedList;
}; // class CircularBuffer
/***********************************************************
 *                Functions definition
************************************************************/
template < typename T, std::size_t size >
auto CircularBuffer<T, size>::put( const T input ) -> void {
    if (m_linkedList.size() == size) {
        m_linkedList.popFront();
    }
    m_linkedList.add(input);
}

template < typename T, std::size_t size >
auto CircularBuffer<T, size>::remove( const T input ) -> void {
    m_linkedList.remove(input);
}

template < typename T, std::size_t size >
auto CircularBuffer<T, size>::removeAll() -> void {
    m_linkedList.clear();
}

template < typename T, std::size_t size >
auto CircularBuffer<T, size>::empty() -> bool {
    return m_linkedList.empty();
}

template < typename T, std::size_t size >
auto CircularBuffer<T, size>::operator[] ( const std::size_t index ) -> T& {
    try {
        return m_linkedList[index];
    } catch (...) {
        throw;
    }
}

#endif
