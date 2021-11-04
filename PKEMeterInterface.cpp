#include "PKEMeterInterface.h"

PKEMeter::PKEMeterInterface::PKEMeterInterface():
	m_AButtonPIN(2),
	m_BButtonPIN(3),
	m_StateLowButtonPIN(4),
	m_StateHighButtonPIN(5),
	m_StateOffButtonPIN(6),
	m_AButtonIsPressed(false),
	m_BButtonIsPressed(false),
	m_SelectorState(PKEMeterSelector::Off)
{

}

void PKEMeter::PKEMeterInterface::Setup()
{

}

void PKEMeter::PKEMeterInterface::Update()
{
	//read button state and change state

}

bool PKEMeter::PKEMeterInterface::AIsPressed()
{
	return false;
}

bool PKEMeter::PKEMeterInterface::BIsPressed()
{
	return false;
}

PKEMeterSelector PKEMeter::PKEMeterInterface::GetSelectorState()
{
	return PKEMeterSelector();
}
