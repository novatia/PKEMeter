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
}