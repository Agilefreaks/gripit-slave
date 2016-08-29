#pragma once

#include"job.h"
#include "gripit_data_store.h"
#include "gripit_address_generator.h"

class AddressAutoAssignmentJob : public Job {
public:
	AddressAutoAssignmentJob(
		GripitDataStore* gripit_data_store, 
		GripitAddressGenerator* gripit_address_generator);
	void run();
private:
	GripitDataStore* gripit_data_store;
	GripitAddressGenerator* gripit_address_generator;
};