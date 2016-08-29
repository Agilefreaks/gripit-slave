#pragma once

#include "gripit_data_store.h"
#include "gripit_sensor_reader.h"
#include "gripit_address_generator.h"
#include "gripit_job_runner.h"

class GripitTask
{
public:
	GripitTask(
		GripitDataStore *gripit_data_store, 
		GripitSensorReader *gripit_sensor_reader, 
		GripitAddressGenerator *gripit_address_generator,
		GripitJobRunner *gripit_job_runner);
	~GripitTask();

	void run();
private:
	GripitDataStore *gripit_data_store;
	GripitSensorReader *gripit_sensor_reader;
	GripitAddressGenerator *gripit_address_generator;
	GripitJobRunner *gripit_job_runner;
};