#ifndef _INPUT_MANAGER_H_
#define _INPUT_MANAGER_H_

#include "Defines.h"

namespace Everdrive
{
	class InputManager
	{
	public:
		InputManager()     {}
		~InputManager()    {}

		void Init();

		BYTE GetKeyboardPort1() const { return m_KeyboardPort1; }
		BYTE GetKeyboardPort2() const { return m_KeyboardPort1; }

	private:
		BYTE m_KeyboardPort1;
		BYTE m_KeyboardPort2;
	};
}

#endif//_INPUT_MANAGER_H_