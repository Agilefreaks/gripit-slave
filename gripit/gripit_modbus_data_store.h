#pragma once

#include "gripit_data_store.h"
#include <ModbusSerial.h>

class GripitModbusDataStore : public GripitDataStore
{
public:
	GripitModbusDataStore(ModbusSerial *modbus_serial);
	~GripitModbusDataStore();

	void setup();
	unsigned int read_value(char entry);
	void store_value(char sensor, unsigned int value);
	bool read_flag(char address);
private:
	ModbusSerial *modbus_serial;
};