#include "Arduino.h"
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
	pinMode(m_AButtonPIN, INPUT);
	pinMode(m_BButtonPIN, INPUT);
	pinMode(m_StateLowButtonPIN, INPUT);
	pinMode(m_StateOffButtonPIN, INPUT);
	pinMode(m_StateHighButtonPIN, INPUT);
}

void PKEMeter::PKEMeterInterface::Update()
{
	//read button state and change state
	int ARead = digitalRead(m_AButtonPIN);
	int BRead = digitalRead(m_BButtonPIN);
	int LowRead = digitalRead(m_StateLowButtonPIN);
	int OffRead = digitalRead(m_StateOffButtonPIN);
	int HighRead = digitalRead(m_StateHighButtonPIN);

	if (ARead == HIGH) {
		m_AButtonIsPressed = true;
	}
	else {
		m_AButtonIsPressed = false;
	}

	if (BRead == HIGH) {
		m_BButtonIsPressed = true;
	}
	else {
		m_BButtonIsPressed = false;
	}

	if (LowRead == HIGH) {
		m_SelectorState = PKEMeterSelector::LowEnergy;
	}
	
	if (OffRead == HIGH) {
		m_SelectorState = PKEMeterSelector::Off;
	}
	
	if (HighRead == HIGH) {
		m_SelectorState = PKEMeterSelector::HighEnergy;
	}
}

bool PKEMeter::PKEMeterInterface::AIsPressed()
{
	return false;
}

bool PKEMeter::PKEMeterInterface::BIsPressed()
{
	return false;
}

PKEMeter::PKEMeterInput* PKEMeter::PKEMeterInterface::GetUserInput()
{
	return new PKEMeterInput(m_AButtonIsPressed,m_BButtonIsPressed,m_SelectorState);
}
