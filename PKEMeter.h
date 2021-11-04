#pragma once
#include "GLoop.h"
#include "Buzzer.h"
#include "PKEMeterInterface.h"
#include "State.h"
#include "StateContext.h"

#define MAX_COMPONENTS 2

namespace PKEMeter {
	class PKEMeter : public  ArduinoApplicationEngine::GLoop
	{

	private:
		Buzzer m_Buzzer;
		PKEMeterInterface m_PKEMeterInterface;
		StateContext m_Context;

		ArduinoApplicationEngine::GLoop* m_Components[MAX_COMPONENTS];

	public:
		PKEMeter();

		/**
		 * GLoop interface
		 */
		virtual void Setup() override;
		virtual void Update() override;

	};
}