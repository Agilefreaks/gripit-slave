#pragma once

#include "gripit_task.h"

#include "test_suite.h"
#include "mock_gripit_data_store.h"
#include "mock_gripit_sensor_reader.h"
#include "mock_gripit_job_runner.h"
#include "mock_gripit_address_generator.h"

class GripitTaskTests : public TestSuite<GripitTaskTests>
{
public:
	GripitTaskTests();

	void setup();
	void teardown();

	GripitTask *gripit_task;
	MockGripitDataStore *gripit_data_store;
	MockGripitSensorReader *gripit_sensor_reader;
	MockGripitAddressGenerator *gripit_address_generator;
	MockGripitJobRunner *gripit_job_runner;
};