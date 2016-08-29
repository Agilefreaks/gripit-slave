#pragma once

#include "gripit_random_number_generator.h"

class GripitArduinoRandomNumberGenerator : public GripitRandomNumberGenerator {
public:
	GripitArduinoRandomNumberGenerator();
	unsigned int generate(unsigned int max_value);
};