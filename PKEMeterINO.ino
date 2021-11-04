// Visual Micro is in vMicro>General>Tutorial Mode
// 
/*
    Name:       PKEMeter.ino
    Created:	18/10/2021 19:25:49
    Author:     Andrea Novati
*/
#include "PKEMeter.h"

PKEMeter::PKEMeter g_PKEMeter;

// The setup() function runs once each time the micro-controller starts
void setup()
{
    //g_Buzzer.SetRandomTone(795,805);
    g_PKEMeter.Setup();
}

// Add the main program code into the continuous loop() function
void loop()
{
    g_PKEMeter.Update();
}