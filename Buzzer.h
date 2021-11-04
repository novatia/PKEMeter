#pragma once
#include "GLoop.h";

namespace PKEMeter {
	enum class BuzzerType {
		Random,
		Constant
	};

	enum class BuzzerTiming {
		Random,
		Constant
	};

	enum class BuzzerAggressivity {
		Default,
		Off,
		Low,
		Medium,
		High
	};

	class Buzzer : public ArduinoApplicationEngine::GLoop {
	public:
		int BUZZ_PIN;
		BuzzerType Type;
		BuzzerTiming Timing;


		unsigned int MinDuration; //uSeconds
		unsigned int MaxDuration; //uSeconds

		unsigned int MinPauseDuration; //uSeconds
		unsigned int MaxPauseDuration; //uSeconds

		Buzzer();
		void SetConstantTone();
		void SetRandomTone();
		void SetConstantTone(unsigned int);
		void SetRandomTone(unsigned int, unsigned int);
		void SetAggressivity(BuzzerAggressivity);
		void Stop();
		void Play();

		/**
		 * GLoop interface
		 */
		virtual void Update() override;
		virtual void Setup() override;

	private:
		BuzzerAggressivity m_Aggressivity;
		bool m_Enabled; //buzzer is active
		bool m_Active; //buzzer is playing sound
		bool m_Playing; //buzzer is playing sound
		bool m_Paused; //buzzer is paused
		int m_PlayerDuration; //played duration [ms]
		int m_PlayerPause; //Pause Duration [ms]
		unsigned int m_PlayerTone; // played frequency
		unsigned long m_CurrentTS;
		unsigned long m_StartTS;
		unsigned int m_MinTone;
		unsigned int m_MaxTone;

		void InitPlayer();

	};
}