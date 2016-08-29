#pragma once

#include "job.h"
#include "gripit_data_store.h"
#include "gripit_sensor_reader.h"

class ReadSensorsJob : public Job
{
public:
	ReadSensorsJob(GripitDataStore *gripit_data_store, GripitSensorReader *gripit_sensor_reader);

	void run();

private:
	GripitDataStore *gripit_data_store;
	GripitSensorReader *gripit_sensor_reader;
};