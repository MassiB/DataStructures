/** @file Exception.cpp
 *  @brief Exception class function definitions 
 *
 *  @author Massinissa Bandou
 *  @bug No known bugs.
 */
/***********************************************************
 *               internal includes
***********************************************************/
#include "Exception.hpp"

/***********************************************************
 *               Function definitions
***********************************************************/
Exception::Exception( const char * error ) : m_error(error) {

}

const char * Exception::what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW {
    return m_error;
}
