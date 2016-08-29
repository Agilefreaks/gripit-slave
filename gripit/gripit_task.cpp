#include "gripit_task.h"
#include "gripit_config.h"
#include "read_sensors_job.h"
#include "address_auto_assignment_job.h"

using namespace gripit;

GripitTask::GripitTask(
	GripitDataStore *gripit_data_store, 
	GripitSensorReader *gripit_sensor_reader,
	GripitAddressGenerator *gripit_address_generator,
	GripitJobRunner *gripit_job_runner)
{
	this->gripit_data_store = gripit_data_store;
	this->gripit_sensor_reader = gripit_sensor_reader;
	this->gripit_address_generator = gripit_address_generator;
	this->gripit_job_runner = gripit_job_runner;
}

GripitTask::~GripitTask()
{
}

void GripitTask::run() {
	Job *job = this->gripit_data_store->read_flag(AUTO_ASSIGNMENT_MODE_FLAG)
		? (Job*)new AddressAutoAssignmentJob(this->gripit_data_store, this->gripit_address_generator)
		: new ReadSensorsJob(this->gripit_data_store, this->gripit_sensor_reader);

	this->gripit_job_runner->run(job);
}