#pragma once
#ifndef mirai_cpp_exceptions_network_exception_hpp_H_
#define mirai_cpp_exceptions_network_exception_hpp_H_

#include <exception>

namespace Cyan
{
	/**
	 * @brief ��������쳣
	*/
	class NetworkException : public std::runtime_error
	{
	public:
		NetworkException(): std::runtime_error("�������.") {}
		virtual ~NetworkException() = default;
	};

}

#endif // !mirai_cpp_exceptions_network_exception_hpp_H_