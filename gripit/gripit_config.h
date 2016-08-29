#pragma once

namespace gripit {
	//Modbus slave address
	const int DEFAULT_SLAVE_ADDRESS = 1;

	//Modbus Registers Offsets (0-9999)
	const char SENSOR1 = 1;
	const char SENSOR2 = 2;
	const char SENSOR3 = 3;
	const char SENSOR4 = 4;
	const char SLAVE_ADDRESS = 5;

	const char REGENERATE_SLAVE_ADDRESS_FLAG = 6;
	const char AUTO_ASSIGNMENT_MODE_FLAG = 7;

	const char ADDRESS_FLAGS_WORD1 = 254;
	const char ADDRESS_FLAGS_WORD2 = 255;

	const unsigned int FLAG_SET_WORD = 1;
	const unsigned int FLAG_NOT_SET_WORD = 0;
}

#ifdef ARDUINO
#include "gripit_arduino_config.h"
#else
#include "gripit_placeholder_config.h"
#endif // ARDUINO