#include "gripit_config.h"
#include "read_sensors_job.h"
#include "address_auto_assignment_job.h"

#include "gripit_task_tests.h"
#include "mocks.h"

using namespace gripit;

void run_always_reads_the_address_auto_assignment_flag_from_the_data_store(GripitTaskTests *context) {
	context->gripit_data_store->read_flag_return_value = true;

	context->gripit_task->run();

	assert(context->gripit_data_store->read_flag_params->size() == 1);
	assert(context->gripit_data_store->read_flag_params->at(0) == AUTO_ASSIGNMENT_MODE_FLAG);
}

void run_when_the_address_auto_assignment_flag_is_set_starts_a_address_auto_assignment_job(GripitTaskTests *context) {
	context->gripit_data_store->read_flag_return_value = true;

	context->gripit_task->run();

	assert(context->gripit_job_runner->run_params->size() == 1);
	assert(instanceof<AddressAutoAssignmentJob>(context->gripit_job_runner->run_params->at(0)));
}

void run_when_the_address_auto_assignment_flag_is_not_set_starts_a_read_sensors_job(GripitTaskTests *context) {
	context->gripit_data_store->read_flag_return_value = false;

	context->gripit_task->run();

	assert(context->gripit_job_runner->run_params->size() == 1);
	assert(instanceof<ReadSensorsJob>(context->gripit_job_runner->run_params->at(0)));
}

GripitTaskTests::GripitTaskTests() {
	this->tests->push_back(run_always_reads_the_address_auto_assignment_flag_from_the_data_store);
	this->tests->push_back(run_when_the_address_auto_assignment_flag_is_set_starts_a_address_auto_assignment_job);
	this->tests->push_back(run_when_the_address_auto_assignment_flag_is_not_set_starts_a_read_sensors_job);
}

void GripitTaskTests::setup() {
	this->gripit_data_store = new MockGripitDataStore();
	this->gripit_sensor_reader = new MockGripitSensorReader();
	this->gripit_job_runner = new MockGripitJobRunner();
	this->gripit_address_generator = new MockGripitAddressGenerator();
	this->gripit_task = new GripitTask(
		this->gripit_data_store,
		this->gripit_sensor_reader,
		this->gripit_address_generator,
		this->gripit_job_runner);
}

void GripitTaskTests::teardown() {
	delete this->gripit_task;
	delete this->gripit_job_runner;
	delete this->gripit_data_store;
	delete this->gripit_sensor_reader;
}