#include <time.h>
#include "gripit_address_generator_tests.h"
#include "gripit_config.h"

using namespace gripit;

unsigned int mock_read_address_with_one_entry(char address) {
	//setup so as to mimic all addresses being taken except 14
	return address == ADDRESS_FLAGS_WORD2 
		? 57343 //‭1101111111111111‬
		: 65535; //1111111111111111‬
}

unsigned int mock_read_address_with_two_entries(char address) {
	//setup so as to mimic all addresses being taken except 4 and 20
	return 65527; //‭1111111111110111‬
}

void generate_always_reads_the_address_flags_entry_values_from_the_store(GripitAddressGeneratorTets* context) {
	context->gripit_address_generator->generate();

	assert(context->gripit_data_store->read_value_params->size() == 2);
	assert(context->gripit_data_store->read_value_params->at(0) == (char)254);
	assert(context->gripit_data_store->read_value_params->at(1) == (char)255);
}

void generate_one_address_is_not_used_returns_the_address(GripitAddressGeneratorTets* context) {
	context->gripit_data_store->read_value_callback = mock_read_address_with_one_entry;

	unsigned int result = context->gripit_address_generator->generate();

	assert(result == 14);
}

void generate_at_least_one_address_is_not_used_generates_a_random_number_less_than_or_equal_to_the_available_address_count(GripitAddressGeneratorTets* context) {
	context->gripit_data_store->read_value_callback = mock_read_address_with_two_entries;

	unsigned int result = context->gripit_address_generator->generate();

	assert(context->gripit_random_number_generator->generate_call_params->size() == 1);
	assert(context->gripit_random_number_generator->generate_call_params->at(0) == 3); //Max address (2) + 1
}

void generate_more_than_one_address_is_not_used_returns_a_random_available_addres(GripitAddressGeneratorTets* context) {
	context->gripit_data_store->read_value_callback = mock_read_address_with_two_entries;

	const int TOTAL_TEST_CALL_COUNT = 10;
	int address1_hit = 0;
	int address2_hit = 0;
	for (int i = 0; i < TOTAL_TEST_CALL_COUNT; i++) {
		int result = context->gripit_address_generator->generate();
		if (result == 4) {
			address1_hit++;
		}
		else if (result == 20) {
			address2_hit++;
		}
	}

	assert(address1_hit > 0);
	assert(address2_hit > 0);
	assert(address1_hit + address2_hit == TOTAL_TEST_CALL_COUNT);
}

GripitAddressGeneratorTets::GripitAddressGeneratorTets() {
	this->tests->push_back(generate_always_reads_the_address_flags_entry_values_from_the_store);
	this->tests->push_back(generate_one_address_is_not_used_returns_the_address);
	this->tests->push_back(generate_at_least_one_address_is_not_used_generates_a_random_number_less_than_or_equal_to_the_available_address_count);
	this->tests->push_back(generate_more_than_one_address_is_not_used_returns_a_random_available_addres);
}

void GripitAddressGeneratorTets::setup() {
	this->gripit_data_store = new MockGripitDataStore();
	this->gripit_random_number_generator = new MockGripitRandomNumberGenerator();
	this->gripit_address_generator = new GripitAddressGenerator(
		this->gripit_data_store, 
		this->gripit_random_number_generator);
}

void GripitAddressGeneratorTets::teardown() {
	delete this->gripit_address_generator;
	delete this->gripit_data_store;
}