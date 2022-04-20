#pragma once
/**
 * Define here the input layout as abstract methods, implemented by the states in order to change state.
 * STATE PATTERN
 */
class PKEMeterKeyboardLayout
{
public:
	virtual void ButtonAPressed() = 0;
	virtual void ButtonBPressed() = 0;
	virtual void SwitchSelectorToLow() = 0;
	virtual void SwitchSelectorToOff() = 0;
	virtual void SwitchSelectorToHigh() = 0;
};

