#pragma once
#include "Gloop.h"
#include "PKEMeterInput.h"

namespace PKEMeter {
	class StateContext;

	class State:
		public ArduinoApplicationEngine::GLoop
	{

	public:
		State();
		virtual ~State();

		void HandleInput(PKEMeterInput);
		virtual void ButtonAPressed() = 0;
		virtual void ButtonBPressed() = 0;
		virtual void SwitchSelectorToLow() = 0;
		virtual void SwitchSelectorToOff() = 0;
		virtual void SwitchSelectorToHigh() = 0;

		/*
		* GLoop virtual interface
		*/
		virtual void Setup() override =0;
		virtual void Update() override =0;

		void SetContext(StateContext*);

	protected:
		StateContext* m_Context;

	};

}
