#pragma once

#include <vector>

#include "gripit_random_number_generator.h"

class MockGripitRandomNumberGenerator : public GripitRandomNumberGenerator {
public:
	MockGripitRandomNumberGenerator();
	unsigned int generate(unsigned int max_value);
	std::vector<unsigned int> *generate_call_params;
	unsigned int ((*generate_callback)(unsigned int));
};
