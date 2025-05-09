#include "PKEMeterState_LowEnergyOperativeMode.h"
#include "PKEMeterState_LowEnergyStage2.h"
#include "PKEMeterState_LowEnergyStage3.h"
#include "PKEMeterState_HighEnergyOperativeMode.h"
#include "PKEMeterState_Off.h"

void PKEMeter::PKEMeterState_LowEnergyOperativeMode::ButtonAPressed()
{
	//Go to LowEnergyStage2
	this->m_Context->TransitionTo(new PKEMeterState_LowEnergyStage2());
}

void PKEMeter::PKEMeterState_LowEnergyOperativeMode::ButtonBPressed()
{
	//Go to LowEnergyStage3
	this->m_Context->TransitionTo(new PKEMeterState_LowEnergyStage3());
}

void PKEMeter::PKEMeterState_LowEnergyOperativeMode::SwitchSelectorToLow()
{
	return;
}

void PKEMeter::PKEMeterState_LowEnergyOperativeMode::SwitchSelectorToOff()
{
	this->m_Context->TransitionTo(new PKEMeterState_Off());
}

void PKEMeter::PKEMeterState_LowEnergyOperativeMode::SwitchSelectorToHigh()
{
	this->m_Context->TransitionTo(new PKEMeterState_HighEnergyOperativeMode());
}

void PKEMeter::PKEMeterState_LowEnergyOperativeMode::Setup()
{
	//LOW ENERGY STAGE 1 SETUP

}

void PKEMeter::PKEMeterState_LowEnergyOperativeMode::Update()
{
	//LOW ENERGY STAGE 1 UPDATE
	//set buzzer to Off

	//servo to position Off

	//show display to Low  

	//Register to stage 1
}

void PKEMeter::PKEMeterState_LowEnergyOperativeMode::HandleInput(ArduinoApplicationEngine::InputLayout* InputLayout)
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
