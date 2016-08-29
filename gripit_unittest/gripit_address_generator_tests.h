#pragma once

#include "gripit_address_generator.h"
#include "test_suite.h"
#include "mock_gripit_data_store.h"
#include "mock_gripit_random_number_generator.h"

class GripitAddressGeneratorTets : public TestSuite<GripitAddressGeneratorTets> {
public:
	GripitAddressGeneratorTets();
	void setup();
	void teardown();
	GripitAddressGenerator* gripit_address_generator;
	MockGripitDataStore* gripit_data_store;
	MockGripitRandomNumberGenerator* gripit_random_number_generator;
};