#pragma once
#ifndef mirai_cpp_events_event_processer_hpp_H_
#define mirai_cpp_events_event_processer_hpp_H_

#include <functional>
#include "defs/serializable.hpp"

namespace Cyan
{
	template<typename T>
	using EventProcessor = std::function<void(T)>;

	typedef Serializable WeakEvent;
	//using WeakEvent = std::function<void(Serializable*)>;


}


#endif // !mirai_cpp_events_event_processer_hpp_H_