#include "Arduino.h"
#include "Buzzer.h"
#include "PKEMeter.h"

using namespace ArduinoApplicationEngine;


PKEMeter::PKEMeter::PKEMeter() :
	m_PKEMeterInterface()
{

}

void PKEMeter::PKEMeter::Setup()
{
	m_Context.Setup();
}

void PKEMeter::PKEMeter::Update()
{
	//Get input from user
	m_PKEMeterInterface.Update();

	//Change state upon input
	m_Context.GetState()->HandleInput( m_PKEMeterInterface.GetUserInput() );

	//Update current device state
	m_Context.Update();

	
}
