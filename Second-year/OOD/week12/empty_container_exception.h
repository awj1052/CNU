#ifndef _EMPTY_CONTAINER_EXCEPTION_H_
#define _EMPTY_CONTAINER_EXCEPTION_H_

#include <stdexcept>

class EmptyContainerException : public std::runtime_error {
 public:
    explicit EmptyContainerException(const char* what) :
        std::runtime_error(what) {}
};

#endif   // _EMPTY_CONTAINER_EXCEPTION_H_
