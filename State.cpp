#include "State.h"
#include "StateContext.h"

PKEMeter::State::State()
{

}

PKEMeter::State::~State()
{

}

void PKEMeter::State::HandleInput(PKEMeterInput)
{
}

void PKEMeter::State::SetContext(StateContext* context)
{
	this->m_Context = context;
}