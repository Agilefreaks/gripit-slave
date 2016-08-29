#include "gripit_address_generator.h"
#include "gripit_config.h"

using namespace gripit;

GripitAddressGenerator::GripitAddressGenerator(
	GripitDataStore *gripit_data_store, 
	GripitRandomNumberGenerator* random_number_generator) {
	this->gripit_data_store = gripit_data_store;
	this->random_number_generator = random_number_generator;
}

unsigned int GripitAddressGenerator::generate() {
	unsigned int flags_map[2];
	unsigned int unused_addresses[32];
	flags_map[1] = this->gripit_data_store->read_value(ADDRESS_FLAGS_WORD1);
	flags_map[0] = this->gripit_data_store->read_value(ADDRESS_FLAGS_WORD2);
	unsigned int unused_addresses_count = 0;
	for (int word_index = 0; word_index < 2; word_index++) {
		for (int index = 0; index < 16; index++) {
			bool is_address_used = (flags_map[word_index] >> index) & 0x0001;
			if (!is_address_used) {
				unused_addresses[unused_addresses_count++] = index + 1 + (16 * word_index);
			}
		}
	}
	
	int random_address_index = this->random_number_generator->generate(unused_addresses_count + 1);
	return unused_addresses[random_address_index];
}