#pragma once
class PKEMeterKeyboardLayout
{
public:
	virtual void ButtonAPressed() = 0;
	virtual void ButtonBPressed() = 0;
	virtual void SwitchSelectorToLow() = 0;
	virtual void SwitchSelectorToOff() = 0;
	virtual void SwitchSelectorToHigh() = 0;
};

