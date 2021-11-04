#pragma once
#include "State.h"
#include "StateContext.h"

namespace PKEMeter {
	class PKEMeterState_HighEnergyOperativeMode :
		public State
	{
	private:

	public:
		virtual void ButtonAPressed() override;
		virtual void ButtonBPressed() override;
		virtual void SwitchSelectorToLow() override;
		virtual void SwitchSelectorToOff() override;
		virtual void SwitchSelectorToHigh() override;

		virtual void Setup() override;
		virtual void Update() override;
	};
}

