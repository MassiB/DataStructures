/** @file LinkedListTest.cpp
 *  @brief Test LinkedList functionalities 
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
#include "../DataStructures/LinkedList.hpp"

/*******************************************************//**
* @namespace : test
* 
***********************************************************/
namespace test {
   /** @class LinkedListTest
    *  @brief This class test LinkedList functionalites
    */
    class LinkedListTest : public ::testing::Test {
    public:
        auto SetUp() -> void {
        }

        auto TearDown() -> void {
        }
        
    protected:
        LinkedList<int> m_linkedList;

        void init() {
            const int size = 5;
            for ( auto i(0); i < size; ++i )
                m_linkedList.add(i);
        }

        void clear() {
            m_linkedList.clear();
        }
    }; // class LinkedListTest
/***********************************************************/
    TEST_F(LinkedListTest, test_add)
    /**
     * @brief Test add function of LinkedList class
     * 
     */
    {
        //Arrange
        init();
        m_linkedList.add(100);
        //Expect
        //Assert
        ASSERT_EQ(6, m_linkedList.size());
        ASSERT_EQ(100, m_linkedList[m_linkedList.size() - 1]);
        //Cleanup
        clear();
    }
/***********************************************************/
    TEST_F(LinkedListTest, test_addFront)
    /**
     * @brief Test addFront function of LinkedList
     * 
     */
    {
        //Arrange
        init();
        m_linkedList.addFront(1);
        m_linkedList.addFront(2);
        //Expect
        //Assert
        ASSERT_EQ(7, m_linkedList.size());
        ASSERT_EQ(2, m_linkedList[0]);
        ASSERT_EQ(1, m_linkedList[1]);
        //Cleanup
        clear();
    }
/***********************************************************/
    // class LinkedListRemoveOptionTest : public ::testing::TestWithParam<> {
    // }; // class LinkedListRemoveOptionTest

    TEST_F(LinkedListTest, test_remove)
    /**
     * @brief Test remove function of LinkedList 
     * 
     */
    {
        //Arrange
        init();
        m_linkedList.add(1);
        m_linkedList.remove(2, REMOVE_FIRST_OF);
        m_linkedList.remove(1, REMOVE_OCCURENCE);
        //Expect
        //Assert
        ASSERT_EQ(3, m_linkedList.size());
        //Cleanup
        clear();
    }
/***********************************************************/
    TEST_F(LinkedListTest, test_clear)
    /**
     * @brief Test clear function of LinkedList class
     * 
     */
    {
        //Arrange
        init();
        m_linkedList.clear();
        //Expect
        //Assert
        ASSERT_EQ(EMPTY, m_linkedList.size());
        ASSERT_TRUE(m_linkedList.empty());
        //Cleanup
        clear();
    }
/***********************************************************/
    TEST_F(LinkedListTest, test_popFront)
    /**
     * @brief Test popFront function of LinkedList class
     * 
     */
    {
        //Arrange
        init();
        //Expect
        //Assert
        m_linkedList.popFront();
        ASSERT_EQ(4, m_linkedList.size());
        ASSERT_EQ(1, m_linkedList[0]);
        //Cleanup
        clear();
    }
/***********************************************************/
    TEST_F(LinkedListTest, test_popBack)
    /**
     * @brief Test popBack function of LinkedList class
     * 
     */
    {
        //Arrange
        init();
        m_linkedList.popBack();
        //Expect
        //Assert
        ASSERT_EQ(4, m_linkedList.size());
        ASSERT_EQ(3, m_linkedList[3]);
        //Cleanup
        clear();
    }
/***********************************************************/
    TEST_F(LinkedListTest, test_size)
    /**
     * @brief Test size function of LinkedList class
     * 
     */
    {
        //Arrange
        init();
        //Expect
        //Assert
        ASSERT_EQ(5, m_linkedList.size());
        //Cleanup
        clear();
    }
/***********************************************************/
    TEST_F(LinkedListTest, test_empty)
    /**
     * @brief Test empty function of LinkedList class
     * 
     */
    {
        //Arrange
        init();
        //Expect
        //Assert
        EXPECT_FALSE(m_linkedList.empty());
        m_linkedList.clear();
        EXPECT_TRUE(m_linkedList.empty());
        //Cleanup
        clear();
    }
/***********************************************************/
    TEST_F(LinkedListTest, test_front)
    /**
     * @brief Test front function of LinkedList class
     * 
     */
    {
        //Arrange
        init();
        //Expect
        //Assert
        EXPECT_EQ(0, m_linkedList.front());
        //Cleanup
        clear();
    }
/***********************************************************/
    TEST_F(LinkedListTest, test_back)
    /**
     * @brief Test back function of LinkedList class
     * 
     */
    {
        //Arrange
        init();
        //Expect
        //Assert
        EXPECT_EQ(4, m_linkedList.back());
        //Cleanup
        clear();
    }
/***********************************************************/
    TEST_F(LinkedListTest, test_reverse)
    /**
     * @brief Test reverse function of LinkedList class
     * 
     */
    {
        //Arrange
        init();
        m_linkedList.reverse();
        //Expect
        //Assert
        std::size_t size = m_linkedList.size();
        for ( auto i(0); i < size; ++i )
            EXPECT_EQ((size - 1 - i), m_linkedList[i]);
        //Cleanup
        clear();
    }
/***********************************************************/
    TEST_F(LinkedListTest, test_find) {

    }
/***********************************************************/
    TEST_F(LinkedListTest, test_insert_good_weather)
    /**
     * @brief Test insert function of LinkedList class
     *        good weather test
     */
    {
        //Arrange
        init();
        auto itr = m_linkedList.begin();
        m_linkedList.insert(-1, itr);
        ++itr;
        m_linkedList.insert(-2, itr);
        //Expect
        //Assert
        EXPECT_EQ(7, m_linkedList.size());
        EXPECT_EQ(-1, m_linkedList[0]);
        EXPECT_EQ(-2, m_linkedList[3]);
        //Cleanup
        clear();
    }
/***********************************************************/
    TEST_F(LinkedListTest, test_insert_bad_weather)
    /**
     * @brief Test insert function of LinkedList class
     *        bad weather test
     */
    {
        //Arrange
        LinkedList<int>::Iterator itr;
        //Expect
        EXPECT_THROW(m_linkedList.insert(100, itr), Exception);
        //Assert
    }   
/***********************************************************/
    TEST_F(LinkedListTest, test_begin)
    /**
     * @brief Test begin function of LinkedList class
     * 
     */
    {
        //Arrange
        init();
        LinkedList<int>::Iterator itr = m_linkedList.begin();
        //Expect
        //Assert
        EXPECT_EQ(0, itr->data);
        //Cleanup
        clear();
    }
/***********************************************************/
    TEST_F(LinkedListTest, test_end)
    /**
     * @brief Test end function of LinkedList class
     * 
     */
    {
        //Arrange
        init();
        LinkedList<int>::Iterator itr = m_linkedList.end();
        //Expect
        //Assert
        EXPECT_EQ(4, itr->data);
        //Cleanup
        clear();
    }
/***********************************************************/
}; // namespace test
