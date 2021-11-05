#include "State.h"
#include "StateContext.h"

ArduinoApplicationEngine::State::State(): m_Context(nullptr)
{

}

ArduinoApplicationEngine::State::~State()
{

}

void ArduinoApplicationEngine::State::HandleInput(InputLayout*)
{
}

void ArduinoApplicationEngine::State::SetContext(StateContext* context)
{
	this->m_Context = context;
}