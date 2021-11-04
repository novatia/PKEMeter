#include "StateContext.h"
#include "State.h"

PKEMeter::StateContext::StateContext() : m_State(nullptr) 
{
	this->TransitionTo(m_State);
}

PKEMeter::StateContext::~StateContext()
{
	delete m_State;
}

void PKEMeter::StateContext::TransitionTo(State* state)
{
		if (this->m_State != nullptr)
			delete this->m_State;

		this->m_State = state;
		this->m_State->SetContext(this);
}

PKEMeter::State* PKEMeter::StateContext::GetState()
{
	return m_State;
}

void PKEMeter::StateContext::PressButtonA()
{
}

void PKEMeter::StateContext::PressButtonB()
{
}

void PKEMeter::StateContext::SwitchSelectorToLow()
{
}

void PKEMeter::StateContext::SwitchSelectorToOff()
{
}

void PKEMeter::StateContext::SwitchSelectorToHigh()
{
}
