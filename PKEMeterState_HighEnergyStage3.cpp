#include "PKEMeterState_HighEnergyStage3.h"
#include "PKEMeterState_HighEnergyStage2.h"
#include "PKEMeterState_LowEnergyStage3.h"
#include "PKEMeterState_Off.h"

void PKEMeter::PKEMeterState_HighEnergyStage3::ButtonAPressed()
{
	this->m_Context->TransitionTo(new PKEMeterState_HighEnergyStage2());
}

/**
 * DO NOTHING
 */
void PKEMeter::PKEMeterState_HighEnergyStage3::ButtonBPressed()
{
	return;
}

void PKEMeter::PKEMeterState_HighEnergyStage3::SwitchSelectorToLow()
{
	this->m_Context->TransitionTo(new PKEMeterState_LowEnergyStage3());
}

void PKEMeter::PKEMeterState_HighEnergyStage3::SwitchSelectorToOff()
{
	this->m_Context->TransitionTo(new PKEMeterState_Off());
}

/*
 * DO NOTHING
 */
void PKEMeter::PKEMeterState_HighEnergyStage3::SwitchSelectorToHigh()
{
	return;
}

void PKEMeter::PKEMeterState_HighEnergyStage3::Setup()
{	
	//HIGH ENERGY STAGE 3 - SETUP
}

void PKEMeter::PKEMeterState_HighEnergyStage3::Update()
{
	//HIGH ENERGY STAGE 3 - UPDATE
	//set buzzer to Hight

	//servo to position Stage 2

	//show display to High  

	//Register to stage 3
}

void PKEMeter::PKEMeterState_HighEnergyStage3::HandleInput(ArduinoApplicationEngine::InputLayout* InputLayout)
{
	PKEMeterInput* Input = reinterpret_cast<PKEMeterInput*>(InputLayout);

	switch (Input->SelectorState)
	{
	case PKEMeterSelector::Off: {
		this->SwitchSelectorToOff();
		break;
	}
	case PKEMeterSelector::LowEnergy: {
		this->SwitchSelectorToLow();
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
