/** @file LinkedList.hpp
 *  @brief Class definition of a doubly linked list
 *
 *  @author Massinissa Bandou
 *  @bug No known bugs.
 */
#ifndef LINKEDLIST_HPP_
#define LINKEDLIST_HPP_

/******************************
 *     std includes
*******************************/
#include <iostream>
#include <thread>
#include <mutex>

/******************************
 *    internal includes
*******************************/
#include "../Misc/node.hpp" 
#include "../Misc/constants.hpp"
#include "../Misc/Exception.hpp"

template < typename T >
/** @class LinkedList
 *  @brief This class define a doubly linked list
 *         of any data type.
 */
class LinkedList final {
public:
    /** @enum REMOVAL_OPTION
    *   @brief options used to remove element from the linked list
    */
    enum REMOVAL_OPTION 
    {
        REMOVE_FIRST_OF = 0,
        REMOVE_ALL
    };
    /***************************************************************************//**
    * @brief : Constructor
    *           
    * @param : none
    ******************************************************************************/
    LinkedList() = default;
    /***************************************************************************//**
    * @brief : Destructor
    *           
    * @param : none
    ******************************************************************************/
    ~LinkedList();
    /***************************************************************************//**
    * @brief : Append a new element to the current linked list
    *           
    * @param : data  - const T type
    ******************************************************************************/
    auto Add( const T data ) -> void;
    /***************************************************************************//**
    * @brief : Remove first element that contains data 
    *           
    * @param : data   - const T type
    *          option - removal option (remove first of element or remove 
    *                                    all elements that contain data)
    ******************************************************************************/
    auto Remove( const T data, REMOVAL_OPTION option = REMOVE_FIRST_OF ) -> void;
    /***************************************************************************//**
    * @brief : Remove all element of the linked list
    *           
    * @param : none
    ******************************************************************************/
    auto Clear() -> void;
    /***************************************************************************//**
    * @brief : remove first element of the linked list
    *           
    * @param : none
    ******************************************************************************/
    auto PopFront() -> void;
    /***************************************************************************//**
    * @brief : remove last element of the linked list
    * 
    * @param : none
    ******************************************************************************/
    auto PopBack() -> void;
    /***************************************************************************//**
    * @brief  : get current linked list size
    * 
    * @param  :  none
    * @return :  std::size_t - size of the current linked list.
    ******************************************************************************/
    auto Size() -> std::size_t;
    /***************************************************************************//**
    * @brief  : check if current linked list is empty
    * 
    * @param  :  none
    * @return :  bool - returns empty if size is equal to 0.
    ******************************************************************************/
    auto Empty() -> bool;
    /***************************************************************************//**
    * @brief  : Return first element of the current linked list 
    * 
    * @param  :  none
    * @return :  T - first element data
    ******************************************************************************/
    auto Front() -> T;
    /***************************************************************************//**
    * @brief  : Return last element of the current linked list 
    * 
    * @param  :  none
    * @return :  T - last element data
    ******************************************************************************/
    auto Back() -> T;
    /***************************************************************************//**
    * @brief : Search index operator
    * 
    * @param in:  out  - 
    * @return  :  T    - value at index
    ******************************************************************************/
    auto operator[] ( const std::size_t index ) -> T&;
    /***************************************************************************//**
    * @brief : chevron operator
    * 
    * @param :  out  - reference to std::ostream
    *           ll   - reference to a LinkedList
    ******************************************************************************/
    friend auto operator << (std::ostream &out, const LinkedList<T> &ll) -> std::ostream& {
        out << CONSOLE_OUTPUT_LEFT_BRACKET 
            << CONSOLE_OUTPUT_SPACING;
        auto n = ll.head;
        while (nullptr != n) {
            out << n->data << CONSOLE_OUTPUT_RIGHT_ARROW;
            n = n->next;
        }
        out << CONSOLE_OUTPUT_RIGHT_BRACKET;
        return out;
    }
private:
    Node<T> *head {nullptr}, 
            *tail {nullptr};
    std::size_t m_size {0};
    std::mutex m_mutex;
}; // class LinkedList

/***********************************************************
 *                Functions definition
************************************************************/
template < typename T >
LinkedList<T>::~LinkedList() {
    removeNodes(head);
    head = tail = nullptr;
}

template < typename T >
auto LinkedList<T>::Add( const T data ) -> void {
    std::lock_guard<std::mutex> guard(m_mutex);
    if (nullptr == head) {
        head = createNewNode(data);
        tail = head;
    } else {
        auto node = createNewNode(data);
        node->prev = tail;
        tail->next = node;
        tail = node;
    }
    m_size++;
}

template < typename T >
auto LinkedList<T>::Remove( const T data, REMOVAL_OPTION option ) -> void {
    std::lock_guard<std::mutex> guard(m_mutex);
    auto node = head;
    while (nullptr != node) {
        if (node->data == data){
            auto prev = node->prev;
            auto next = node->next;
            if (head == node) head = next;
            if (tail == node) tail = next;
            if (nullptr != prev) {
                prev->next = next;
                if (nullptr != next)
                    next->prev = prev;
            }
            delete node;
            if (option == REMOVE_FIRST_OF) break;
        }
        node = node->next;
    }
}

template < typename T >
auto LinkedList<T>::Clear() -> void {
    removeNodes(head);
    head = nullptr;
    tail = nullptr;
} 

template < typename T >
auto LinkedList<T>::PopFront() -> void {
    std::lock_guard<std::mutex> guard(m_mutex);
    auto node = head;
    if (nullptr != node) {
        if (tail == node) tail = node->next;
        head = node->next;
        if (nullptr != head) head->prev = nullptr;
        delete node;
        m_size--;
    }
}

template < typename T >
auto LinkedList<T>::PopBack() -> void {
    std::lock_guard<std::mutex> guard(m_mutex);
    auto node = tail;
    if (nullptr != node) {
        tail = node->prev;
        if (head == node) head = tail;
        if (nullptr != tail) tail->next = nullptr;
        delete node;
        m_size--;
    }
}

template < typename T >
auto LinkedList<T>::Size() -> std::size_t {
    return m_size;
}

template < typename T >
auto LinkedList<T>::Empty() -> bool {
    return (m_size == 0);
}

template < typename T >
auto LinkedList<T>::Front() -> T {
    //if (nullptr == head) throw Exception("Access to null memory");
    return head->data;
}

template < typename T >
auto LinkedList<T>::Back() -> T {
    //if (nullptr == tail) throw Exception("Access to null memory");
    return tail->data;
}

template < typename T >
auto LinkedList<T>::operator[] ( const std::size_t index ) -> T& {
    auto node = head;
    for ( auto i(0); i < index; ++i ) {
        if (nullptr == node) throw Exception("Index out of range");
        node = node->next;
    }
    return *node;
}

#endif
