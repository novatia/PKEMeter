#pragma once
#include "State.h"
#include "StateContext.h"
#include "PKEMeterKeyboardLayout.h"

namespace PKEMeter {
    class PKEMeterState_LowEnergyStage2 :
        public ArduinoApplicationEngine::State, public PKEMeterKeyboardLayout
    {
	private:

	public:
		/**
		 * Keyboard layout interface
		 */
		virtual void ButtonAPressed() override;
		virtual void ButtonBPressed() override;
		virtual void SwitchSelectorToLow() override;
		virtual void SwitchSelectorToOff() override;
		virtual void SwitchSelectorToHigh() override;

		/**
		 * GLoop Interface
		 */
		virtual void Setup() override;
		virtual void Update() override;

		/**
		 * State
		 */
		virtual void HandleInput(ArduinoApplicationEngine::InputLayout*) override;
    };
}
