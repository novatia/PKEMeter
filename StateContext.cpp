#include "StateContext.h"
#include "State.h"

ArduinoApplicationEngine::StateContext::StateContext() : m_State(nullptr) 
{
	this->TransitionTo(m_State);
}

ArduinoApplicationEngine::StateContext::~StateContext()
{
	delete m_State;
}

void ArduinoApplicationEngine::StateContext::TransitionTo(State* state)
{
		if (this->m_State != nullptr)
			delete this->m_State;

		this->m_State = state;
		this->m_State->SetContext(this);
}

ArduinoApplicationEngine::State* ArduinoApplicationEngine::StateContext::GetState()
{
	return m_State;
}