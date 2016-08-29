#pragma once

#include "gripit_sensor_reader.h"

class GripitArduinoSensorReader : public GripitSensorReader {
public:
	GripitArduinoSensorReader();
	~GripitArduinoSensorReader();

	int read_sensor(char sensor);
};