#include "gripit_arduino_sensor_reader.h"
#include "Arduino.h"

GripitArduinoSensorReader::GripitArduinoSensorReader() {
}

GripitArduinoSensorReader::~GripitArduinoSensorReader() {
}

int GripitArduinoSensorReader::read_sensor(char sensor) {
	return analogRead(sensor);
}