#include "address_auto_assignment_job.h"
#include "gripit_config.h"

using namespace gripit;

AddressAutoAssignmentJob::AddressAutoAssignmentJob(
	GripitDataStore* gripit_data_store, 
	GripitAddressGenerator* gripit_address_generator) {
	this->gripit_data_store = gripit_data_store;
	this->gripit_address_generator = gripit_address_generator;
}

void AddressAutoAssignmentJob::run() {
	if (this->gripit_data_store->read_flag(REGENERATE_SLAVE_ADDRESS_FLAG)) {
		unsigned int new_address = this->gripit_address_generator->generate();
		this->gripit_data_store->store_value(SLAVE_ADDRESS, new_address);
		this->gripit_data_store->store_value(REGENERATE_SLAVE_ADDRESS_FLAG, FLAG_NOT_SET_WORD);
	}
}