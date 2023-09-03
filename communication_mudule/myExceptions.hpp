#ifndef MY_EXCEPTIONS_HPP
#define MY_EXCEPTIONS_HPP

#include <stdexcept>
#include <exception>

namespace net{ //network

class CommunicationError : public std::runtime_error
{
public:
    using std::runtime_error::runtime_error;
};

class CreateSocketError : public net::CommunicationError
{
public:
    using net::CommunicationError::CommunicationError;
};

class BindingSocketError : public net::CommunicationError
{
public:
    using net::CommunicationError::CommunicationError;
};

class ListenError : public net::CommunicationError
{
public:
    using net::CommunicationError::CommunicationError;
};

class AcceptError : public net::CommunicationError
{
public:
    using net::CommunicationError::CommunicationError;
};

class ReadError : public net::CommunicationError
{
public:
    using net::CommunicationError::CommunicationError;
};

class WriteError : public net::CommunicationError
{
public:
    using net::CommunicationError::CommunicationError;
};

class FileDiscreptorError : public net::CommunicationError
{
public:
    using net::CommunicationError::CommunicationError;
};

}//namespace net

#endif