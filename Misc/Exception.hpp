/** @file Exception.hpp
 *  @brief Exception class 
 *
 *  @author Massinissa Bandou
 *  @bug No known bugs.
 */
#ifndef EXCEPTION_HPP_
#define EXCEPTION_HPP_

/***********************************************************
 *                   std includes
***********************************************************/
#include <exception>

/** @class Exception
 *  @brief Class defines exception handling
 */
class Exception : public std::exception {
public:
    /***************************************************************************//**
    * @brief : Constructor
    *           
    * @param : none
    ******************************************************************************/
    Exception(const char *error);
    /***************************************************************************//**
    * @brief : Destructor
    *           
    * @param : none
    ******************************************************************************/
    ~Exception() = default;
    /***************************************************************************//**
    * @brief : Returns the general error
    *           
    * @param : none
    ******************************************************************************/
    const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override;

private:
    const char * m_error {""};
};

#endif
