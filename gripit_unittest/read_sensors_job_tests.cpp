#include "gripit_config.h"

#include "read_sensors_job_tests.h"
#include "mocks.h"

using namespace gripit;

void run_always_reads_the_4_sensor_values(ReadSensorsJobTests *context) {
	context->read_sensors_job->run();

	assert(context->gripit_sensor_reader->read_sensor_params->size() == 4);
	assert(context->gripit_sensor_reader->read_sensor_params->at(0) == SENSOR_PIN1);
	assert(context->gripit_sensor_reader->read_sensor_params->at(1) == SENSOR_PIN2);
	assert(context->gripit_sensor_reader->read_sensor_params->at(2) == SENSOR_PIN3);
	assert(context->gripit_sensor_reader->read_sensor_params->at(3) == SENSOR_PIN4);
}

void run_always_stores_the_4_read_sensor_values(ReadSensorsJobTests *context) {
	const int RETURNED_VALUE = 13;
	context->gripit_sensor_reader->read_sensor_return_value = RETURNED_VALUE;

	context->read_sensors_job->run();

	assert(context->gripit_data_store->store_value_params->size() == 4);
	std::array<char, 2> expected_args1 = { SENSOR1, RETURNED_VALUE };
	std::array<char, 2> expected_args2 = { SENSOR2, RETURNED_VALUE };
	std::array<char, 2> expected_args3 = { SENSOR3, RETURNED_VALUE };
	std::array<char, 2> expected_args4 = { SENSOR4, RETURNED_VALUE };
	assert(context->gripit_data_store->store_value_params->at(0) == expected_args1);
	assert(context->gripit_data_store->store_value_params->at(1) == expected_args2);
	assert(context->gripit_data_store->store_value_params->at(2) == expected_args3);
	assert(context->gripit_data_store->store_value_params->at(3) == expected_args4);
}

ReadSensorsJobTests::ReadSensorsJobTests() {
	this->tests->push_back(run_always_reads_the_4_sensor_values);
	this->tests->push_back(run_always_stores_the_4_read_sensor_values);
}

void ReadSensorsJobTests::setup() {
	this->gripit_data_store = new MockGripitDataStore();
	this->gripit_sensor_reader = new MockGripitSensorReader();
	this->read_sensors_job = new ReadSensorsJob(this->gripit_data_store, this->gripit_sensor_reader);
}

void ReadSensorsJobTests::teardown() {
	delete this->read_sensors_job;
	delete this->gripit_data_store;
	delete this->gripit_sensor_reader;
}