#include "PKEMeterStateContext.h"

void PKEMeter::PKEMeterStateContext::Setup()
{
	m_Buzzer.SetConstantTone(800);
	m_Buzzer.SetAggressivity(BuzzerAggressivity::High);
	m_Buzzer.Play();
}

void PKEMeter::PKEMeterStateContext::Update()
{
	m_State->Update();
}
