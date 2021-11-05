#pragma once
#include "GLoop.h"
#include "PKEMeterInput.h"
#include "PKEMeterSelector.h"

namespace PKEMeter {

	class PKEMeterInterface : public ArduinoApplicationEngine::GLoop
	{
		/*
		 *
			- Stage1
				When neither button is pressed,
				the sketch
				 - will return the the servo to the parked position,
				 - it plays sound Low Buzzer
				 - Sequences the slow speed version of the LED’s

			- Stage2
				When “Button A” becomes pressed:
					- the servo moves to 1st position
					- plays sound Medium buzzer
					- sequences the medium speed version of the LED’s

				if the button is released, returns to Stage1

			 - Stage3
				When “Button B” becomes pressed:
					the servo moves to 2nd position
					plays sound High
					sequences the fast speed version of the LED’s
				if the button is released, returns to Stage1

				The buttons are programmed with a 1.5 second delay on release,
				this gives you time to press another button without the wings instantly returning to Stage1.
			*/

	private:
		unsigned int m_AButtonPIN;
		unsigned int m_BButtonPIN;
		unsigned int m_StateLowButtonPIN;
		unsigned int m_StateHighButtonPIN;
		unsigned int m_StateOffButtonPIN;

		bool m_AButtonIsPressed;
		bool m_BButtonIsPressed;
		PKEMeterSelector m_SelectorState; //0 low energy - 1 Off - 2 High energy 

	public:
		PKEMeterInterface();
		virtual void Setup() override;
		virtual void Update() override;

		bool AIsPressed();
		bool BIsPressed();
		PKEMeterInput* GetUserInput();
	};
}