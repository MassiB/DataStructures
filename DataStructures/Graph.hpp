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
    const T from, to;
    const int weight;
};

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
    Graph( const unsigned int n );
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
    auto Add( const EDGE<T> edge ) -> void;
    /***************************************************************************//**
    * @brief : Function to add list of edges
    * 
    * @param :  edges - list of edges
    ******************************************************************************/
    auto Add( const std::list<EDGE<T>> edges ) -> void;
    /***************************************************************************//**
    * @brief : chevron operator
    * 
    * @param :  out  -  reference to std::ostream
    *           GR   -  reference to Graph structure
    ******************************************************************************/
    friend auto operator << ( std::ostream &out, const Graph<T> &GR ) -> std::ostream& {
        for ( auto i(0); i < GR.vertices; ++i ) {
            out << GR.m_AdjacencyList[i] << CONSOLE_OUTPUT_NEW_LINE;
        }
        return out;
    }

private:
    LinkedList<T> *m_AdjacencyList {nullptr};
    const int vertices;
    /***************************************************************************//**
    * @brief : Find an element in the adjacency list 
    * 
    * @param : input 
    ******************************************************************************/
    auto Find( const T input ) -> const int;
}; // class Graph

/***********************************************************
 *                Functions definition
************************************************************/
template < typename T >
Graph<T>::Graph( const unsigned int v ) : vertices(v) {
    m_AdjacencyList = new LinkedList<T>[vertices];
}

template < typename T >
Graph<T>::~Graph() {
    delete[] m_AdjacencyList;
}

template < typename T >
auto Graph<T>::Find( const T input ) -> const int {
    for ( auto i(0); i < vertices; ++i ) {
        if (m_AdjacencyList[i].Empty()) continue;
        if (input == m_AdjacencyList[i].Front()) 
            return i; 
    }
    return NOT_DEFINED;
}

template < typename T >
auto Graph<T>::Add( const EDGE<T> edge ) -> void {
    auto Edge_Pos = Find(edge.from);
    static int index = 0;
    if (NOT_DEFINED != Edge_Pos) {
        m_AdjacencyList[Edge_Pos].Add(edge.to);
    } else {
        try {
            m_AdjacencyList[index].Add(edge.from);
            m_AdjacencyList[index].Add(edge.to);
            index++;
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }   
    }
}

template < typename T >
auto Graph<T>::Add( const std::list<EDGE<T>> edges ) -> void {
    for ( auto l : edges ) {
        Add(l);
    }
}

#endif