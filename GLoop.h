#pragma once

namespace ArduinoApplicationEngine {
	
	class GLoop
	{
	public:
		virtual void Update() = 0;
		virtual void Setup() = 0;
	};

}