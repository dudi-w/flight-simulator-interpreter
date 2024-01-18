#ifndef COMMUNICATION_EXCEPTIONS_HPP
#define COMMUNICATION_EXCEPTIONS_HPP

#include "../base_exception.hpp"

namespace net{ //network

class CommunicationError : public fp::BaseException
{
public:
    using fp::BaseException::BaseException;
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