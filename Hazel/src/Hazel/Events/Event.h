#pragma once

#include "Core.h"

#include <string>
#include <sstream>
#include <functional>

namespace Hazel {

	enum class EventType {
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		KeyPressed, KeyReleased,
		AppTick, AppUpdate, AppRender,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};
	enum EventCategory {
		None = 0,
		EventCategoryApplication	=	BIT(0),
		EventCategoryInput			=	BIT(1),
		EventCategoryKeyboard		=	BIT(2),
		EventCategoryMouse			=	BIT(3),
		EventCategoryMouseButton	=	BIT(4)
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char *GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	class HZAPI Event
	{
		friend class EventDispatcher;
	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category) const
		{
			return GetCategoryFlags() & category;
		}

	protected:
		bool m_Handled = false;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		os << e.ToString();
		return os;
	}

}