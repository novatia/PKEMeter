#include "PKEMeterState_LowEnergyStage3.h"
#include "PKEMeterState_HighEnergyStage3.h"
#include "PKEMeterState_LowEnergyStage2.h"
#include "PKEMeterState_Off.h"

void PKEMeter::PKEMeterState_LowEnergyStage3::ButtonAPressed()
{
	this->m_Context->TransitionTo(new PKEMeterState_LowEnergyStage2());
}

/*
 * DO NOTHING
 */
void PKEMeter::PKEMeterState_LowEnergyStage3::ButtonBPressed()
{
	return;
}

/*
 * DO NOTHING
 */
void PKEMeter::PKEMeterState_LowEnergyStage3::SwitchSelectorToLow()
{
	return;
}

void PKEMeter::PKEMeterState_LowEnergyStage3::SwitchSelectorToOff()
{
	this->m_Context->TransitionTo(new PKEMeterState_Off());
}

void PKEMeter::PKEMeterState_LowEnergyStage3::SwitchSelectorToHigh()
{
	this->m_Context->TransitionTo(new PKEMeterState_HighEnergyStage3());
}

void PKEMeter::PKEMeterState_LowEnergyStage3::Setup()
{
	//LOW ENERGY STAGE 3 - SETUP
}

void PKEMeter::PKEMeterState_LowEnergyStage3::Update()
{
	//LOW ENERGY STAGE 3 - UPDATE
	//set buzzer to High

	//servo to position Stage 2

	//show display to Low  

	//Register to stage 3
}

void PKEMeter::PKEMeterState_LowEnergyStage3::HandleInput(ArduinoApplicationEngine::InputLayout* InputLayout)
{
	PKEMeterInput* Input = reinterpret_cast<PKEMeterInput*>(InputLayout);

	switch (Input->SelectorState)
	{
	case PKEMeterSelector::Off: {
		this->SwitchSelectorToOff();
		break;
	}
	case PKEMeterSelector::HighEnergy: {
		this->SwitchSelectorToHigh();
		break;
	}
	default:
		break;
	}

	if (Input->APressed)
		this->ButtonAPressed();

	if (Input->BPressed)
		this->ButtonBPressed();
}
