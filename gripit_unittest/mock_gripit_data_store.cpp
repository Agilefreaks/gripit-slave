#include "mock_gripit_data_store.h"

MockGripitDataStore::MockGripitDataStore() {
	this->store_value_params = new std::vector<std::array<char, 2>>();
	this->read_flag_params = new std::vector<char>();
	this->read_value_params = new std::vector<char>();

	this->read_flag_return_value = false;
	this->read_value_callback = nullptr;
}

MockGripitDataStore::~MockGripitDataStore() {
	delete this->store_value_params;
	delete this->read_flag_params;
	delete this->read_value_params;
}

void MockGripitDataStore::setup() {
}

void MockGripitDataStore::store_value(char entry, unsigned int value) {
	std::array<char, 2> params = { entry, value };
	this->store_value_params->push_back(params);
}

bool MockGripitDataStore::read_flag(char address) {
	this->read_flag_params->push_back(address);
	return this->read_flag_return_value;
}

unsigned int MockGripitDataStore::read_value(char entry) {
	this->read_value_params->push_back(entry);
	return this->read_value_callback == nullptr
		? 1
		: this->read_value_callback(entry);
}