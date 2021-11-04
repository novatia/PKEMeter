#pragma once
namespace PKEMeter {
	class State;

	class StateContext {
	private:
		State* m_State;

	public:
		StateContext();
		virtual ~StateContext();

		void TransitionTo(State*);
		State* GetState();

		void PressButtonA();
		void PressButtonB();
		void SwitchSelectorToLow();
		void SwitchSelectorToHigh();
		void SwitchSelectorToOff();
	};
}

