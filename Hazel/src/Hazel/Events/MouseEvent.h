#pragma once
#include "Event.h"

namespace Hazel {

	class HZAPI MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float x, float y)
			: m_MouseX(x), m_MouseY(y) { }
		inline float GetX() const { return m_MouseX; }
		inline float GetY() const { return m_MouseY; }

		EVENT_CLASS_TYPE(MouseMoved);
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)

	private:
		float m_MouseX, m_MouseY;
	};

	class HZAPI MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float x, float y)
			: m_XOffset(x), m_YOffset(y) { }

		inline float GetXOffset() const { return m_XOffset; }
		inline float GetYPffset() const { return m_YOffset; }

		EVENT_CLASS_TYPE(MouseScrolled);
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse);

	private:
		float m_XOffset, m_YOffset;
	};

	class HZAPI MouseButtonEvent : public Event
	{
	public:
		inline int GetMouseButton() const { return m_Button; }
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse);

	protected:
		MouseButtonEvent(int button)
			: m_Button(button) {}

		int m_Button;
	};

	class HZAPI MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button)
			: MouseButtonEvent(button) {}

		EVENT_CLASS_TYPE(MouseButtonPressed);
	};

	class HZAPI MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button)
			: MouseButtonEvent(button) {}

		EVENT_CLASS_TYPE(MouseButtonReleased);
	};

}