#pragma once

class GripitDataStore
{
public:
	GripitDataStore();
	~GripitDataStore();

	virtual void setup() = 0;
	virtual unsigned int read_value(char address) = 0;
	virtual void store_value(char address, unsigned int value) = 0;
	virtual bool read_flag(char address) = 0;
};