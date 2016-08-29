#pragma once

#include "gripit_data_store.h"
#include "gripit_random_number_generator.h"

class GripitAddressGenerator {
public:	
	GripitAddressGenerator(GripitDataStore* gripit_data_store, GripitRandomNumberGenerator* random_number_generator);
	virtual unsigned int generate();

private:
	GripitDataStore* gripit_data_store;
	GripitRandomNumberGenerator* random_number_generator;
};
