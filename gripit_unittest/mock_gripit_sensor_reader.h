#pragma once

#include "gripit_sensor_reader.h"
#include <vector>

class MockGripitSensorReader : public GripitSensorReader {
public:
	MockGripitSensorReader();
	~MockGripitSensorReader();

	int read_sensor(char sensor);
	int read_sensor_return_value;
	std::vector<int> *read_sensor_params;
};
