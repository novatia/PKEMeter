#pragma once
#include "InputLayout.h"
#include "PKEMeterSelector.h"

namespace PKEMeter {

	struct PKEMeterInput: 
		public ArduinoApplicationEngine::InputLayout
	{
		bool APressed;
		bool BPressed;
		PKEMeterSelector SelectorState;

		PKEMeterInput(bool,bool, PKEMeterSelector);
		virtual ~PKEMeterInput() override;
	};

}
