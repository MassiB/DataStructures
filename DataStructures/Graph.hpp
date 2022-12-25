/** @file Graph.hpp
 *  @brief Class definition of a graph data structure
 * 
 *  Graph class describes a network of data 
 * 
 *  @author Massinissa Bandou
 *  @bug No known bugs.
 */
#ifndef GRAPH_HPP_
#define GRAPH_HPP_

/***********************************************************
 *                   std includes
***********************************************************/
#include <iostream>
#include <exception>
#include <list>

/***********************************************************
 *               internal includes
***********************************************************/
#include "LinkedList.hpp"
#include "../Misc/constants.hpp"

template < typename T >
/** @struct EDGE
 *  @brief This structure defines edges 
 */
struct EDGE {
    EDGE() = delete;
    EDGE( const T _from, const T _to, const int w = 0 ) : 
        from(_from), to(_to), weight(w) {}
    ~EDGE() = default;
    const T from, to;
    const int weight;
}; // struct EDGE

template < typename T >
/** @class Graph
 *  @brief This class defines a graph data structure
 */
class Graph final {
public:
    /***************************************************************************//**
    * @brief : Constructor
    *           
    * @param : none
    ******************************************************************************/
    explicit Graph( std::size_t n);
    /***************************************************************************//**
    * @brief : Destructor
    *           
    * @param : none
    ******************************************************************************/
    ~Graph();
    /***************************************************************************//**
    * @brief : Function to add new edge
    * 
    * @param :  edge - single edge
    ******************************************************************************/
    auto add( const EDGE<T> edge ) -> void;
    /***************************************************************************//**
    * @brief : Function to add list of edges
    * 
    * @param :  edges - list of edges
    ******************************************************************************/
    auto add( const std::list<EDGE<T>> edges ) -> void;
    /***************************************************************************//**
    * @brief : Get number of vertices
    * 
    * @param :  none
    * @return:  number of vertices
    ******************************************************************************/
    auto num_vertices() -> std::size_t;
private:
    LinkedList<T> *m_AdjacencyList {nullptr};
    std::size_t vertices;
    /***************************************************************************//**
    * @brief : Find an element in the adjacency list 
    * 
    * @param : input 
    ******************************************************************************/
    auto find( const T input ) -> std::size_t;
}; // class Graph
/***********************************************************
 *                Functions definition
************************************************************/
template < typename T >
Graph<T>::Graph( std::size_t v ) : vertices(v) {
    m_AdjacencyList = new LinkedList<T>[vertices];
}

template < typename T >
Graph<T>::~Graph() {
    delete[] m_AdjacencyList;
}

template < typename T >
auto Graph<T>::find( const T input ) -> std::size_t {
    for ( auto i(0); i < vertices; ++i ) {
        if (m_AdjacencyList[i].empty()) continue;
        try {
            if (input == m_AdjacencyList[i].front()) 
                return i;
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        } 
    }
    return NOT_DEFINED;
}

template < typename T >
auto Graph<T>::add( const EDGE<T> edge ) -> void {
    auto Edge_Pos = find(edge.from);
    static int index = 0;
    if (NOT_DEFINED != Edge_Pos) {
        m_AdjacencyList[Edge_Pos].add(edge.to);
    } else {
        try {
            m_AdjacencyList[index].add(edge.from);
            m_AdjacencyList[index].add(edge.to);
            index++;
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }   
    }
}

template < typename T >
auto Graph<T>::add( const std::list<EDGE<T>> edges ) -> void {
    for ( auto l : edges ) {
        add(l);
    }
}

template < typename T >
auto Graph<T>::num_vertices() -> std::size_t {
    return vertices;
}

#endif