#pragma once

#include "gripit_address_generator.h"

class MockGripitAddressGenerator : public GripitAddressGenerator {
public:
	MockGripitAddressGenerator();

	unsigned int generate();

	int generate_return_value;
	int generate_call_count;
};
