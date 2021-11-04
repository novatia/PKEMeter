#include "PKEMeterState_HighEnergyStage2.h"
#include "PKEMeterState_LowEnergyStage2.h"
#include "PKEMeterState_HighEnergyStage3.h"
#include "PKEMeterState_Off.h"

void PKEMeter::PKEMeterState_HighEnergyStage2::ButtonBPressed()
{
	//Go to HighEnergyStage3
	this->m_Context->TransitionTo(new PKEMeterState_HighEnergyStage3());
}

/*
* DO NOTHING
*/
void PKEMeter::PKEMeterState_HighEnergyStage2::ButtonAPressed()
{
	return;
}
/*
* DO NOTHING
*/
void PKEMeter::PKEMeterState_HighEnergyStage2::SwitchSelectorToHigh()
{
	return;
}

void PKEMeter::PKEMeterState_HighEnergyStage2::SwitchSelectorToLow()
{
	//Go to LowEnergyStage2
	this->m_Context->TransitionTo(new PKEMeterState_LowEnergyStage2());
}

void PKEMeter::PKEMeterState_HighEnergyStage2::SwitchSelectorToOff()
{
	this->m_Context->TransitionTo(new PKEMeterState_Off());
}


void PKEMeter::PKEMeterState_HighEnergyStage2::Setup()
{
	//HIGH ENERGY STAGE 2 - SETUP
}

void PKEMeter::PKEMeterState_HighEnergyStage2::Update()
{
	//HIGH ENERGY STAGE 2 - UPDATE
}
