#include "Arduino.h"
#include "Buzzer.h"

PKEMeter::Buzzer::Buzzer() :  Type(BuzzerType::Constant),
					Timing(BuzzerTiming::Constant), 
					BUZZ_PIN(12), 
					MinDuration(5), 
					MaxDuration(15),
					MinPauseDuration(50),
					MaxPauseDuration(150), 
					m_Active(false), 
					m_Enabled(true),
					m_PlayerTone(0), 
					m_PlayerDuration(0), 
					m_CurrentTS(0),
					m_MinTone(780),
					m_MaxTone(810),
					m_Aggressivity(BuzzerAggressivity::Default)
{

		pinMode(BUZZ_PIN, OUTPUT);
}



void PKEMeter::Buzzer::SetAggressivity(BuzzerAggressivity Aggressivity) {
	m_Aggressivity = Aggressivity;
	InitPlayer();
}

void PKEMeter::Buzzer::SetConstantTone() {
	Type = BuzzerType::Constant;
	InitPlayer();
}

void PKEMeter::Buzzer::SetRandomTone() {
	Type = BuzzerType::Random;
	InitPlayer();
}

void PKEMeter::Buzzer::SetConstantTone(unsigned int Tone)
{
	m_MinTone = Tone;
	SetConstantTone();
}

void PKEMeter::Buzzer::SetRandomTone(unsigned int MinTone, unsigned int MaxTone)
{
	m_MinTone = MinTone;
	m_MaxTone = MaxTone;
	SetRandomTone();
}

void PKEMeter::Buzzer::Play()
{
	if (!m_Active) {
		m_Active = true;
	}
}

void PKEMeter::Buzzer::Stop() {
	m_Active = false;
}

void PKEMeter::Buzzer::InitPlayer()
{
	m_PlayerPause = rand() % MaxPauseDuration + MinPauseDuration;

	switch (m_Aggressivity)
	{
	case BuzzerAggressivity::Default: {
		MinDuration = 5;
		MaxDuration = 15;
		MinPauseDuration = 50;
		MaxPauseDuration = 150;

		break;
	}
	case BuzzerAggressivity::Off: {
		MinDuration = 0;
		MaxDuration = 0;
		MinPauseDuration = 0;
		MaxPauseDuration = 0;
		break;
	}
	case BuzzerAggressivity::Low: {
		MinDuration = 7;
		MaxDuration = 15;
		MinPauseDuration = 1000;
		MaxPauseDuration = 2500;
		break;
	}

	case BuzzerAggressivity::Medium: {
		MinDuration = 5;
		MaxDuration = 15;
		MinPauseDuration = 50;
		MaxPauseDuration = 150;
		break;
	}

	case BuzzerAggressivity::High: {
		MinDuration = 3;
		MaxDuration = 8;
		MinPauseDuration = 25;
		MaxPauseDuration = 75;
		break;
	}
	};


	switch (Type) {
	case BuzzerType::Random: {
		m_PlayerPause = rand() % MaxPauseDuration + MinPauseDuration;
		m_PlayerDuration = rand() % MaxDuration + MinDuration;
		m_PlayerTone = rand() % m_MaxTone + m_MinTone;
		break;
	}

	case BuzzerType::Constant: {
		m_PlayerDuration = MinDuration;
		m_PlayerTone = m_MinTone;
		break;
	}
	};

	m_StartTS = millis();
}

void PKEMeter::Buzzer::Update() {

	if (!m_Enabled) {
		return;
	}
	


	unsigned long current_TS = millis();

	//activating
	if (!m_Active)
		return;

	if (m_Aggressivity == BuzzerAggressivity::Off) {
		if (m_Playing)
		{
			noTone(BUZZ_PIN);
			m_Playing = false;
		}
	}

	//Playing
	if (!m_Playing) {
		tone(BUZZ_PIN, m_PlayerTone);
		m_Playing = true;
	}
	
	//Pause
	if (!m_Paused) 
	{
		if (current_TS >= m_StartTS + m_PlayerDuration) {
			noTone(BUZZ_PIN);
			m_Paused = true;
		}
	}

	//Ending, reset player and run again
	if (current_TS >= m_StartTS + m_PlayerDuration + m_PlayerPause) {
		m_Playing = false;
		m_Paused = false;

		InitPlayer();
	}
}

void PKEMeter::Buzzer::Setup()
{
}
