#pragma once

#include <vector>
#include <array>
#include "gripit_data_store.h"

class MockGripitDataStore : public GripitDataStore
{
public:
	MockGripitDataStore();
	~MockGripitDataStore();

	void setup();
	unsigned int read_value(char address);
	void store_value(char address, unsigned int value);
	bool read_flag(char address);

	std::vector<std::array<char, 2>>* store_value_params;
	std::vector<char>* read_flag_params;
	std::vector<char>* read_value_params;

	bool read_flag_return_value;
	unsigned int(*read_value_callback)(char address);
};