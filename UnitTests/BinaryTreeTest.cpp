/** @file BinaryTessTest.cpp
 *  @brief Test BinaryTree methodes
 *
 *  @author Massinissa Bandou
 *  @bug No known bugs.
 */
/***********************************************************
 *               Gtest includes
***********************************************************/
#include <gtest/gtest.h>

/***********************************************************
 *               Internal includes
***********************************************************/
#include "../DataStructures/BinaryTree.hpp"

/*******************************************************//**
* @namespace : test
* 
***********************************************************/
namespace test {

    class BinaryTreeTest : public ::testing::Test {
    public:
        auto SetUp() -> void {
        }

        auto TearDown() -> void {
        }
    protected:
        BinaryTree<int> BT;
    }; // class BinaryTreeTest
/***********************************************************/
    TEST_F(BinaryTreeTest, test_insert) {

    }
/***********************************************************/
    TEST_F(BinaryTreeTest, test_find) {

    }
/***********************************************************/ 
    TEST_F(BinaryTreeTest, test_clear) {

    }
/***********************************************************/
    TEST_F(BinaryTreeTest, test_length) {

    }
/***********************************************************/    
}; // namespace test
