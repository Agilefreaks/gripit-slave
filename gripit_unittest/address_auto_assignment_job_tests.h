#pragma once

#include "address_auto_assignment_job.h"
#include "mock_gripit_address_generator.h"
#include "test_suite.h"
#include "mock_gripit_data_store.h"

class AddressAutoAssignmentJobTests : public TestSuite<AddressAutoAssignmentJobTests> {
public:
	AddressAutoAssignmentJobTests();
	void setup();
	void teardown();
	AddressAutoAssignmentJob* address_auto_assignment_job;
	MockGripitDataStore* gripit_data_store;
	MockGripitAddressGenerator* gripit_address_generator;
};