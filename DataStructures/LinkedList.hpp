#ifndef LINKEDLIST_HPP_
#define LINKEDLIST_HPP_

/******************************
 *     std includes
*******************************/
#include <iostream>
/******************************
 *    internal includes
*******************************/
#include "node.hpp" 
#include "../Misc/constants.hpp"

template < typename T >
class LinkedList final {
public:
    /***************************************************************************//**
    * Brief: Constructor
    *           
    * @param : none
    ******************************************************************************/
    LinkedList() {}
    /***************************************************************************//**
    * Brief: Destructor
    *           
    * @param : none
    ******************************************************************************/
    ~LinkedList() { 
        removeNodes(head);
        head = tail = nullptr;
    }
    /***************************************************************************//**
    * Brief: remove first element of the LinkedList
    *           
    * @param : none
    ******************************************************************************/
    auto Add(const T data) -> void {
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
    /***************************************************************************//**
    * Brief: remove first element of the LinkedList
    *           
    * @param : none
    ******************************************************************************/
    auto PopFront() -> void {
        auto node = head;
        if (nullptr != node) {
            if (tail == node) tail = node->next;
            head = node->next;
            head->prev = nullptr;
            delete node;
            m_size--;
        }
    }
    /***************************************************************************//**
    * Brief: remove last element of the LinkedList
    * 
    * @param : none
    ******************************************************************************/
    auto PopBack() -> void {
        auto node = tail;
        if (nullptr != node) {
            tail = node->prev;
            if (head == node) head = tail;
            if (nullptr != tail) tail->next = nullptr;
            delete node;
            m_size--;
        }
    }
    /***************************************************************************//**
    * Brief: chevron operator
    * 
    * @param :  out : std::ostream
    *           ll  : LinkedList
    ******************************************************************************/
    friend std::ostream& operator << (std::ostream &out, const LinkedList<T> &ll) {
        out << CONSOLE_OUTPUT_LEFT_BRACKET << CONSOLE_OUTPUT_SPACING;
        auto n = ll.head;
        while (nullptr != n) {
            out << n->data << CONSOLE_OUTPUT_SPACING;
            n = n->next;
        }
        out << CONSOLE_OUTPUT_RIGHT_BRACKET;
        return out;
    }
    /***************************************************************************//**
    * Brief: get current LinkedList size
    * 
    * @param    :  node
    * @return   :  size : std::size_t 
    ******************************************************************************/
    auto Size() -> std::size_t {
        return m_size;
    }

private:
    Node<T> *head{nullptr}, 
            *tail{nullptr};
    std::size_t m_size {0};
}; // class LinkedList

#endif