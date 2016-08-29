#include "address_auto_assignment_job_tests.h"
#include "gripit_config.h"

using namespace gripit;

void run_always_reads_the_generate_id_flag_from_the_data_store(AddressAutoAssignmentJobTests* context) {
	context->address_auto_assignment_job->run();

	assert(context->gripit_data_store->read_flag_params->size() == 1);
	assert(context->gripit_data_store->read_flag_params->at(0) == REGENERATE_SLAVE_ADDRESS_FLAG);
}

void run_generate_id_flag_is_set_writes_a_generated_address_to_the_data_store(AddressAutoAssignmentJobTests* context) {
	context->gripit_data_store->read_flag_return_value = true;
	context->gripit_address_generator->generate_return_value = 27;

	context->address_auto_assignment_job->run();

	std::array<char, 2> params = { SLAVE_ADDRESS, 27 };
	assert(context->gripit_data_store->store_value_params->at(0) == params);
}

void run_generate_id_flag_is_set_toggles_the_flag(AddressAutoAssignmentJobTests* context) {
	context->gripit_data_store->read_flag_return_value = true;
	context->gripit_address_generator->generate_return_value = 27;

	context->address_auto_assignment_job->run();

	std::array<char, 2> params = { REGENERATE_SLAVE_ADDRESS_FLAG, FLAG_NOT_SET_WORD };
	assert(context->gripit_data_store->store_value_params->at(1) == params);
}

AddressAutoAssignmentJobTests::AddressAutoAssignmentJobTests() {
	this->tests->push_back(run_always_reads_the_generate_id_flag_from_the_data_store);	
	this->tests->push_back(run_generate_id_flag_is_set_writes_a_generated_address_to_the_data_store);
	this->tests->push_back(run_generate_id_flag_is_set_toggles_the_flag);
}

void AddressAutoAssignmentJobTests::setup() {
	this->gripit_data_store = new MockGripitDataStore();
	this->gripit_address_generator = new MockGripitAddressGenerator();
	this->address_auto_assignment_job = new AddressAutoAssignmentJob(this->gripit_data_store, this->gripit_address_generator);
}

void AddressAutoAssignmentJobTests::teardown() {
	delete this->address_auto_assignment_job;
	delete this->gripit_data_store;
	delete this->gripit_address_generator;
}