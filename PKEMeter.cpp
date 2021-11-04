#include "Arduino.h"
#include "Buzzer.h"
#include "PKEMeter.h"

using namespace ArduinoApplicationEngine;


PKEMeter::PKEMeter::PKEMeter() :
	m_Buzzer(),
	m_PKEMeterInterface()
{

}

void PKEMeter::PKEMeter::Setup()
{
	m_Buzzer.SetConstantTone(800);
	m_Buzzer.SetAggressivity(BuzzerAggressivity::High);
	m_Buzzer.Play();

	m_Components[0] = dynamic_cast<GLoop*> ( &m_Buzzer );
}

void PKEMeter::PKEMeter::Update()
{
	//Get input from user
	m_PKEMeterInterface.Update();

	//Change state


	//Update current state
	m_Context.GetState()->Update();


	//Update components
	for (int i=0;i<MAX_COMPONENTS;i++)
	{
		GLoop* current_component = m_Components[i];
		current_component->Update();
	}

}
