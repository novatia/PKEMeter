#pragma once
#include "Gloop.h"
#include "PKEMeterInput.h"

namespace ArduinoApplicationEngine {
	class StateContext;

	class State:
		public ArduinoApplicationEngine::GLoop
	{

	public:
		State();
		virtual ~State();

		virtual void HandleInput(InputLayout*) = 0;

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
