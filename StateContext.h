#pragma once
#include "State.h"

namespace ArduinoApplicationEngine {

	class StateContext {
	protected:
		State* m_State;

	public:
		StateContext();
		virtual ~StateContext();

		virtual void TransitionTo(State*);
		State* GetState();
	};
}

