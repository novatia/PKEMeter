#include "PKEMeterState_LowEnergyOperativeMode.h"
#include "PKEMeterState_HighEnergyStage2.h"
#include "PKEMeterState_HighEnergyStage3.h"
#include "PKEMeterState_HighEnergyOperativeMode.h"
#include "PKEMeterState_Off.h"

void PKEMeter::PKEMeterState_HighEnergyOperativeMode::ButtonAPressed()
{
	//Go to HighEnergyStage2
	this->m_Context->TransitionTo( new PKEMeterState_HighEnergyStage2() );
}

void PKEMeter::PKEMeterState_HighEnergyOperativeMode::ButtonBPressed()
{
	//Go to HighEnergyStage3
	this->m_Context->TransitionTo( new PKEMeterState_HighEnergyStage3() );
}

void PKEMeter::PKEMeterState_HighEnergyOperativeMode::SwitchSelectorToLow()
{
	this->m_Context->TransitionTo( new PKEMeterState_LowEnergyOperativeMode() );
}

void PKEMeter::PKEMeterState_HighEnergyOperativeMode::SwitchSelectorToOff()
{
	this->m_Context->TransitionTo( new PKEMeterState_Off() );
}

/*
* DO NOTHING
*/
void PKEMeter::PKEMeterState_HighEnergyOperativeMode::SwitchSelectorToHigh()
{
	return;
}

void PKEMeter::PKEMeterState_HighEnergyOperativeMode::Setup()
{
	//HIGH ENERGY STAGE 1 - SETUP
}

void PKEMeter::PKEMeterState_HighEnergyOperativeMode::Update()
{
	//HIGH ENERGY STAGE 1 - UPDATE

	//set buzzer to Off

	//servo to position Off

	//show display to High  

	//Register to stage 1

}

void PKEMeter::PKEMeterState_HighEnergyOperativeMode::HandleInput(ArduinoApplicationEngine::InputLayout* InputLayout)
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
