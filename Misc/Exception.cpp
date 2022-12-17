#include "Exception.hpp"

Exception::Exception(const char * error) : m_error(error) {

}

const char * Exception::what() const {
    return m_error;
}
