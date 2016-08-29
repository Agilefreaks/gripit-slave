#include "mock_gripit_address_generator.h"

MockGripitAddressGenerator::MockGripitAddressGenerator()
	:GripitAddressGenerator(nullptr, nullptr) {
	this->generate_return_value = 0;
	this->generate_call_count = 0;
}

unsigned int MockGripitAddressGenerator::generate() {
	this->generate_call_count++;
	return this->generate_return_value;
}