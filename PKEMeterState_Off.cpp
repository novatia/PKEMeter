#include "PKEMeterState_Off.h"
#include "PKEMeterState_LowEnergyOperativeMode.h"
#include "PKEMeterState_HighEnergyOperativeMode.h"
/**
 * Do nothing
 */
void PKEMeter::PKEMeterState_Off::ButtonAPressed()
{
	return;
}

/**
 * Do nothing
 */
void PKEMeter::PKEMeterState_Off::ButtonBPressed()
{
	return;
}

/**
 * Do nothing
 */
void PKEMeter::PKEMeterState_Off::Update()
{
	//SHUT DOWN DEVICES

}

/**
 * Do nothing
 */
void PKEMeter::PKEMeterState_Off::SwitchSelectorToOff()
{
	return;
}

/**
 * On to Low Energy operative Mode
 */
void PKEMeter::PKEMeterState_Off::SwitchSelectorToLow()
{
	this->m_Context->TransitionTo(new PKEMeterState_LowEnergyOperativeMode());
}

/**
 * On to High Energy operative Mode
 */
void PKEMeter::PKEMeterState_Off::SwitchSelectorToHigh()
{
	this->m_Context->TransitionTo(new PKEMeterState_HighEnergyOperativeMode());
}

void PKEMeter::PKEMeterState_Off::Setup()
{

}

void PKEMeter::PKEMeterState_Off::HandleInput(ArduinoApplicationEngine::InputLayout* InputLayout)
{
	PKEMeterInput* Input = reinterpret_cast<PKEMeterInput*>(InputLayout);

	switch (Input->SelectorState)
	{
	case PKEMeterSelector::HighEnergy: {
		this->SwitchSelectorToHigh();
		break;
	}
	case PKEMeterSelector::LowEnergy: {
		this->SwitchSelectorToLow();
		break;
	}
	default:
		break;
	}
}
