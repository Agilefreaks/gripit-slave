#include <Modbus.h>
#include <ModbusSerial.h>

#include "gripit_data_store.h"
#include "gripit_modbus_data_store.h"
#include "gripit_sensor_reader.h"
#include "gripit_arduino_sensor_reader.h"
#include "gripit_immediate_job_runner.h"
#include "gripit_address_generator.h"
#include "gripit_task.h"
#include "gripit_arduino_random_number_generator.h"

ModbusSerial* modbus_serial = new ModbusSerial();
GripitDataStore* gripit_data_store = new GripitModbusDataStore(modbus_serial);
GripitSensorReader* gripit_sensor_reader = new GripitArduinoSensorReader();
GripitJobRunner* gripit_job_runner = new GripitImmediateJobRunner();
GripitArduinoRandomNumberGenerator* gripit_random_number_generator = new GripitArduinoRandomNumberGenerator();
GripitAddressGenerator* gripit_address_generator = new GripitAddressGenerator(gripit_data_store, gripit_random_number_generator);
GripitTask *gripit_task = new GripitTask(
	gripit_data_store, 
	gripit_sensor_reader, 
	gripit_address_generator, 
	gripit_job_runner);

void setup() {
	gripit_data_store->setup();
}

void loop() {
  modbus_serial->task();
  gripit_task->run();
}
