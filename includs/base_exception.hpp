#ifndef BASE_EXCEPTION_HPP
#define BASE_EXCEPTION_HPP

#include <stdexcept>

namespace fp { 

class BaseException : public std::runtime_error {
public:
    using std::runtime_error::runtime_error;
};

} // namespace fp

#endif
