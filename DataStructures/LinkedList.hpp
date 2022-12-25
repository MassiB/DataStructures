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

/** @enum REMOVE_ENUM
*   @brief options used to remove elements from a linked list
*/
enum REMOVE_ENUM 
{
    REMOVE_FIRST_OF = 0,
    REMOVE_OCCURENCE
}; // enum REMOVE_ENUM

template < typename T >
/** @class LinkedList
 *  @brief This class define a doubly linked list
 *         of any data type.
 */
class LinkedList final {
public:
    class Iterator {
    public:
        /******************************************************************//**
        * @brief : Constructor
        *           
        * @param : none
        **********************************************************************/
        Iterator() = default;
        /******************************************************************//**
        * @brief : Destructor
        *           
        * @param : none
        **********************************************************************/
        ~Iterator() = default;
        /******************************************************************//**
        * @brief : Post increment operator
        *           
        * @param : none
        **********************************************************************/
        auto operator++() -> Iterator&;
        /******************************************************************//**
        * @brief : Post decrement operator
        *           
        * @param : none
        **********************************************************************/
        auto operator--() -> Iterator&;
        /******************************************************************//**
        * @brief : Dereference operator
        *           
        * @param : none
        * @return: Pointer to current node
        **********************************************************************/
        auto operator->() -> Node<T>*;
    private:
        Node<T> *current_node {nullptr};
        friend class LinkedList<T>;
    }; // class Iterator
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
    * @param in: data  - const T type
    ******************************************************************************/
    auto add( const T data ) -> void;
    /***************************************************************************//**
    * @brief : Add new element to the head of the current linked list
    *           
    * @param in: data  - const T type
    ******************************************************************************/
    auto addFront( const T data ) -> void;
    /***************************************************************************//**
    * @brief : Remove first or all elements that contain data 
    *           
    * @param in: data   - const T type
    * @param in: option - removal option (remove first of element or remove 
    *                                     all elements that contain data)
    ******************************************************************************/
    auto remove( const T data, REMOVE_ENUM option = REMOVE_FIRST_OF ) -> void;
    /***************************************************************************//**
    * @brief : Remove all element of the linked list
    *           
    * @param : none
    ******************************************************************************/
    auto clear() -> void;
    /***************************************************************************//**
    * @brief : remove first element of the linked list
    *           
    * @param : none
    ******************************************************************************/
    auto popFront() -> void;
    /***************************************************************************//**
    * @brief : remove last element of the linked list
    * 
    * @param : none
    ******************************************************************************/
    auto popBack() -> void;
    /***************************************************************************//**
    * @brief  : get current linked list size
    * 
    * @param  :  none
    * @return :  std::size_t - size of the current linked list.
    ******************************************************************************/
    auto size() const -> std::size_t;
    /***************************************************************************//**
    * @brief  : check if current linked list is empty
    * 
    * @param  :  none
    * @return :  bool - returns empty if size is equal to 0.
    ******************************************************************************/
    auto empty() const -> bool;
    /***************************************************************************//**
    * @brief  : Return first element of the current linked list 
    * 
    * @param  :  none
    * @return :  T - first element data
    ******************************************************************************/
    auto front() const -> T;
    /***************************************************************************//**
    * @brief  : Return last element of the current linked list 
    * 
    * @param  :  none
    * @return :  T - last element data
    ******************************************************************************/
    auto back() const -> T;
    /***************************************************************************//**
    * @brief  : Reverse the current linked list 
    * 
    * @param  :  none
    ******************************************************************************/
    auto reverse() -> void;
    /***************************************************************************//**
    * @brief  : Find first node that contains data 
    * 
    * @param  in:  data - const T
    * @return   :  Reference to the iterator
    ******************************************************************************/
    auto find( const T data ) const -> Iterator&;
    /***************************************************************************//**
    * @brief  : Find first node that contains data 
    * 
    * @param  in:  data - const T
    * @param  in:  pos - iterator position
    ******************************************************************************/
    auto insert( const T data, Iterator &pos ) -> void;
    /***************************************************************************//**
    * @brief  : Return reference to begining of the iterator
    * 
    * @param  :  none
    * @return :  Reference of the iterator
    ******************************************************************************/
    auto begin() -> Iterator&;
    /***************************************************************************//**
    * @brief  : Return reference to end of the iterator
    * 
    * @param  :  none
    * @return :  Reference of the iterator
    ******************************************************************************/
    auto end() -> Iterator&;
    /***************************************************************************//**
    * @brief : Search index operator
    * 
    * @param in:  index 
    * @return  :  Reference to   
    ******************************************************************************/
    auto operator[] ( const std::size_t index ) -> T&;
private:
    Node<T> *head {nullptr}, 
            *tail {nullptr};
    Iterator itr;
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
auto LinkedList<T>::add( const T data ) -> void {
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
auto LinkedList<T>::addFront( const T data ) -> void {
    if (nullptr == head) {
        add(data);
    } else {
        auto new_node = createNewNode(data, head);
        head->prev = new_node;
        head = new_node;
        m_size++;
    }
}

template < typename T >
auto LinkedList<T>::remove( const T data, REMOVE_ENUM option ) -> void {
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
            m_size--;
            if (option == REMOVE_FIRST_OF) break;
            else node = next;
        } else {
            node = node->next;
        } 
    }
}

template < typename T >
auto LinkedList<T>::clear() -> void {
    std::lock_guard<std::mutex> guard(m_mutex);
    removeNodes(head);
    head = nullptr;
    tail = nullptr;
    m_size = 0;
} 

template < typename T >
auto LinkedList<T>::popFront() -> void {
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
auto LinkedList<T>::popBack() -> void {
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
auto LinkedList<T>::size() const -> std::size_t {
    return m_size;
}

template < typename T >
auto LinkedList<T>::empty() const -> bool {
    return (m_size == 0);
}

template < typename T >
auto LinkedList<T>::front() const -> T {
    if (nullptr == head) 
        throw Exception("Access to a non allocated memory");
    return head->data;
}

template < typename T >
auto LinkedList<T>::back() const -> T {
    if (nullptr == tail) 
        throw Exception("Access to a non allocated memory");
    return tail->data;
}

template < typename T >
auto LinkedList<T>::operator[] ( const std::size_t index ) -> T& {
    if (index >= m_size)
        throw Exception("Index out of range");
    auto node = head;
    for ( auto i(0); i < index; ++i ) {
        node = node->next;
    }
    return node->data;
}

template < typename T >
auto LinkedList<T>::reverse() -> void {
    std::lock_guard<std::mutex> guard(m_mutex);
    auto node = head;
    tail = node;
    Node<T> *prev = nullptr;
    while (nullptr != node) {
        auto next = node->next;
        node->next = prev;
        node->prev = next;
        prev = node;
        node = next;
        if (nullptr != next)
            head = next;
    }
}

template < typename T >
auto LinkedList<T>::find( const T data ) const -> Iterator& {
    for ( auto itr = begin(); itr != end(); ++itr ) {
        if (itr->data == data)
            return itr;
    }
}

template < typename T >
auto LinkedList<T>::insert( const T data, Iterator &pos ) -> void {
    std::lock_guard<std::mutex> guard(m_mutex);
    auto current_node = pos.current_node;
    if (nullptr == current_node)
        throw Exception("Access to a non allocated memory");
    if (current_node == tail) {
        add(data);
    } else if (current_node == head) {
        addFront(data);
    } else {
        auto new_node = createNewNode(data, current_node->next, current_node->prev);
        current_node->next = new_node;
        auto next = new_node->next;
        if (nullptr != next)
            next->prev = new_node;
        m_size++;
    }
}

template < typename T >
auto LinkedList<T>::begin() -> Iterator& {
    itr.current_node = head;
    return itr;
}

template < typename T >
auto LinkedList<T>::end() -> Iterator& {
    itr.current_node = tail;
    return itr;
}

template < typename T >
auto LinkedList<T>::Iterator::operator++() -> Iterator& {
    current_node = current_node->next;
    return *this;
}

template < typename T >
auto LinkedList<T>::Iterator::operator--() -> Iterator& {
    current_node = current_node->prev;
    return *this;
}

template < typename T >
auto LinkedList<T>::Iterator::operator->() -> Node<T>* {
    return current_node;
}

#endif
