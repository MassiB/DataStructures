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
    LinkedList() {}
    
    ~LinkedList() { 
        removeNodes(head);
        head = tail = nullptr;
    }

    void Add(const T data) {
        if (nullptr == head) {
            head = createNewNode(data);
            tail = head;
        } else {
            auto node = createNewNode(data);
            node->prev = tail;
            tail->next = node;
            tail = node;
        }
    }

    void PopFront() {
        auto node = head;
        if (nullptr != node) {
            if (tail == node) tail = node->next;
            head = node->next;
            head->prev = nullptr;
            delete node;
        }
    }

    void PopBack() {
        auto node = tail;
        if (nullptr != node) {
            tail = node->prev;
            if (head == node) head = tail;
            tail->next = nullptr;
            delete node;
        }
    }

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

private:
    Node<T> *head{nullptr}, 
            *tail{nullptr};
};

#endif