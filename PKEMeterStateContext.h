#pragma once
#include "StateContext.h"
#include "Buzzer.h"
#include <Servo.h>

namespace PKEMeter {
    class PKEMeterStateContext :
        public ArduinoApplicationEngine::StateContext, public ArduinoApplicationEngine::GLoop
    {
    private:
        Buzzer m_Buzzer;
    
    public:
        /**
        * GLoop Interface
        */
        virtual void Setup() override;
        virtual void Update() override;
    };
}

