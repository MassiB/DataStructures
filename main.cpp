/** @file main.cpp
 *  @brief main thread 
 *          
 *  This main program executed simple display
 *  of using data structures such as Circular buffer
 *  Linked List and Binary Tree
 * 
 *  @author Massinissa Bandou
 *  @bug No known bugs.
 */
/***********************************************************
 *                   Gtest includes
***********************************************************/
#include <gtest/gtest.h>
/***********************************************************
 *                  Internal includes
***********************************************************/
#include "UnitTests/LinkedListTest.cpp"
#include "UnitTests/CircularBufferTest.cpp"
#include "UnitTests/BinaryTreeTest.cpp"
#include "UnitTests/GraphTest.cpp"

int main( int argc, char *argv[] ) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
} // main thread
