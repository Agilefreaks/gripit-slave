#include "mock_gripit_random_number_generator.h"

MockGripitRandomNumberGenerator::MockGripitRandomNumberGenerator() {
	this->generate_call_params = new std::vector<unsigned int>();
	this->generate_callback = nullptr;
}

unsigned int MockGripitRandomNumberGenerator::generate(unsigned int max_value) {
	this->generate_call_params->push_back(max_value);
	return this->generate_callback != nullptr
		? this->generate_callback(max_value)
		: this->generate_call_params->size() % 2 == 0;
}