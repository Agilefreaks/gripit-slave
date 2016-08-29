#include "read_sensors_job.h"
#include "gripit_config.h"

using namespace gripit;

ReadSensorsJob::ReadSensorsJob(GripitDataStore *gripit_data_store, GripitSensorReader *gripit_sensor_reader)
{
	this->gripit_data_store = gripit_data_store;
	this->gripit_sensor_reader = gripit_sensor_reader;
}

void ReadSensorsJob::run() {
	this->gripit_data_store->store_value(SENSOR1,
		this->gripit_sensor_reader->read_sensor(SENSOR_PIN1));
	this->gripit_data_store->store_value(SENSOR2,
		this->gripit_sensor_reader->read_sensor(SENSOR_PIN2));
	this->gripit_data_store->store_value(SENSOR3,
		this->gripit_sensor_reader->read_sensor(SENSOR_PIN3));
	this->gripit_data_store->store_value(SENSOR4,
		this->gripit_sensor_reader->read_sensor(SENSOR_PIN4));
}