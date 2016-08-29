#pragma once

#include "read_sensors_job.h"

#include "test_suite.h"
#include "mock_gripit_data_store.h"
#include "mock_gripit_sensor_reader.h"

class ReadSensorsJobTests : public TestSuite<ReadSensorsJobTests>
{
public:
	ReadSensorsJobTests();

	void setup();
	void teardown();

	ReadSensorsJob *read_sensors_job;
	MockGripitDataStore *gripit_data_store;
	MockGripitSensorReader *gripit_sensor_reader;
};