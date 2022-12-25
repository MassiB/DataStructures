/** @file CircularBufferTest.cpp
 *  @brief Test CircularBuffer methodes
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
#include "../DataStructures/CircularBuffer.hpp"

/***********************************************************
 *                   defines
***********************************************************/
#define BUFFER_SIZE   (5)

/*******************************************************//**
* @namespace : test
* 
***********************************************************/
namespace test {
    /** @class CircularBufferTest
    *  @brief This class is defined to test 
    *         CircularBuffer functionalities
    */
    class CircularBufferTest : public ::testing::Test {
    public:
        auto SetUp() -> void {
        }

        auto TearDown() -> void {
        }
    protected:
        CircularBuffer<int , BUFFER_SIZE> CB;
    }; // class CircularBufferTest
/***********************************************************/
    TEST_F(CircularBufferTest, test_put) 
    /**
     * @brief Test put function of CircularBuffer 
     *        class.
     */
    {
        //Arrange
        CB.put(1);
        CB.put(2);
        CB.put(3);
        CB.put(4);
        CB.put(5);
        CB.put(6);
        //Expect
        //Assert
        ASSERT_EQ(2, CB[0]);
        ASSERT_EQ(3, CB[1]);
        ASSERT_EQ(4, CB[2]);
        ASSERT_EQ(5, CB[3]);
        ASSERT_EQ(6, CB[4]);
    }
/***********************************************************/
    TEST_F(CircularBufferTest, test_remove)
    /**
     * @brief Test remove function of CircularBuffer
     *        class.
     */
    {
        //Arrange
        CB.put(1);
        CB.put(2);
        CB.put(3);
        CB.remove(2);
        //Expect
        //Assert
        ASSERT_EQ(1, CB[0]);
        ASSERT_EQ(3, CB[1]);
    }
/***********************************************************/
    TEST_F(CircularBufferTest, test_removeAll)
    /**
     * @brief Test removeAll function of CircularBuffer
     *        class.
     */
    {
        //Arrange
        CB.put(1);
        CB.put(2);
        CB.put(3);
        //Expect
        //Assert
        ASSERT_FALSE(CB.empty());
        CB.removeAll();
        ASSERT_TRUE(CB.empty());
    }
/***********************************************************/
}; // namespace test
