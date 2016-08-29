#include "gripit_config.h"
#include "gripit_arduino_random_number_generator.h"

using namespace gripit;

GripitArduinoRandomNumberGenerator::GripitArduinoRandomNumberGenerator() {
	randomSeed(analogRead(RANDOM_INPUT_PIN));
}

unsigned int GripitArduinoRandomNumberGenerator::generate(unsigned int max_value) {
	return random(0, max_value + 1);
}