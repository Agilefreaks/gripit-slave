#include "mock_gripit_sensor_reader.h"

MockGripitSensorReader::MockGripitSensorReader() {
	this->read_sensor_params = new std::vector<int>();
}

MockGripitSensorReader::~MockGripitSensorReader() {
	delete this->read_sensor_params;
}

int MockGripitSensorReader::read_sensor(char sensor) {
	this->read_sensor_params->push_back(sensor);
	return this->read_sensor_return_value;
}