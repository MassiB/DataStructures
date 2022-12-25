/** @file GraphTest.cpp
 *  @brief Test Graph methodes
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
#include "../DataStructures/Graph.hpp"

/*******************************************************//**
* @namespace : test
* 
***********************************************************/
namespace test {
    class GraphTest : public ::testing::Test {
    public:
        auto SetUp() -> void {
        }

        auto TearDown() -> void {
        }
    protected:
        Graph<int> GR{3};
    }; // class GraphTest
/***********************************************************/
    TEST_F(GraphTest, test_add) {
        //Arrange
        EDGE<int> edg1(0,1);
        EDGE<int> edg2(1,2);
        EDGE<int> edg3(0,2);
        GR.add(edg1);
        GR.add(edg2);
        GR.add(edg3);
        //Expect
        //Assert

    }
}; // namespace test