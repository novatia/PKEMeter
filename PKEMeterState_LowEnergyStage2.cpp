#include "PKEMeterState_LowEnergyStage2.h"
#include "PKEMeterState_HighEnergyStage2.h"
#include "PKEMeterState_LowEnergyStage3.h"
#include "PKEMeterState_Off.h"

/**
 * DO NOTHING
 */
void PKEMeter::PKEMeterState_LowEnergyStage2::ButtonAPressed()
{
	return;
}

void PKEMeter::PKEMeterState_LowEnergyStage2::ButtonBPressed()
{
	this->m_Context->TransitionTo(new PKEMeterState_LowEnergyStage3());
}

/*
 * DO NOTHING
 */
void PKEMeter::PKEMeterState_LowEnergyStage2::SwitchSelectorToLow()
{
	return;
}

void PKEMeter::PKEMeterState_LowEnergyStage2::SwitchSelectorToOff()
{
	this->m_Context->TransitionTo(new PKEMeterState_Off());
}

void PKEMeter::PKEMeterState_LowEnergyStage2::SwitchSelectorToHigh()
{
	this->m_Context->TransitionTo(new PKEMeterState_HighEnergyStage2());
}

void PKEMeter::PKEMeterState_LowEnergyStage2::Setup()
{
	//LOW ENERGY STAGE 2 - SETUP
}

void PKEMeter::PKEMeterState_LowEnergyStage2::Update()
{
	//LOW ENERGY STAGE 2 - UPDATE
	//set buzzer to Low

	//servo to position Stage 1

	//show display to Low  

	//Register to stage 2
}

void PKEMeter::PKEMeterState_LowEnergyStage2::HandleInput(ArduinoApplicationEngine::InputLayout* InputLayout)
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
