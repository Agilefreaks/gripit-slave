#include "gripit_modbus_data_store.h"
#include "gripit_config.h"

using namespace gripit;

GripitModbusDataStore::GripitModbusDataStore(ModbusSerial *modbus_serial)
{
	this->modbus_serial = modbus_serial;
}

GripitModbusDataStore::~GripitModbusDataStore()
{
}

void GripitModbusDataStore::setup() {
	// Config Modbus Serial (port, speed, byte format) 
	// 38400 was the default baud rate
	this->modbus_serial->config(&Serial, 115200, SERIAL_8N1, RTS_PIN);
	// Set the Slave ID (1-247)
	this->modbus_serial->setSlaveId(DEFAULT_SLAVE_ADDRESS);

	this->modbus_serial->addHreg(AUTO_ASSIGNMENT_MODE_FLAG);
	this->modbus_serial->addHreg(SENSOR1);
	this->modbus_serial->addHreg(SENSOR2);
	this->modbus_serial->addHreg(SENSOR3);
	this->modbus_serial->addHreg(SENSOR4);
	this->modbus_serial->addHreg(REGENERATE_SLAVE_ADDRESS_FLAG);
	this->modbus_serial->addHreg(SLAVE_ADDRESS, this->modbus_serial->getSlaveId());
}

unsigned int GripitModbusDataStore::read_value(char address) {
	return this->modbus_serial->Hreg(address);
}

void GripitModbusDataStore::store_value(char address, unsigned int value) {
	this->modbus_serial->Hreg(address, value);
	if (address == SLAVE_ADDRESS) {
		this->modbus_serial->setSlaveId(address);
	}
}

bool GripitModbusDataStore::read_flag(char address) {
	return this->modbus_serial->Hreg(address) == FLAG_SET_WORD;
}