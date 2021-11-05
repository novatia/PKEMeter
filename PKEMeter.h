#pragma once
#include "GLoop.h"
#include "Buzzer.h"
#include "PKEMeterInterface.h"
#include "State.h"
#include "PKEMeterStateContext.h"

#define MAX_COMPONENTS 2

namespace PKEMeter {
	class PKEMeter : public  ArduinoApplicationEngine::GLoop
	{

	private:
		PKEMeterInterface m_PKEMeterInterface;
		PKEMeterStateContext m_Context;

	public:
		PKEMeter();

		/**
		 * GLoop interface
		 */
		virtual void Setup() override;
		virtual void Update() override;

	};
}