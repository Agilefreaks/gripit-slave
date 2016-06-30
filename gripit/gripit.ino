#include <Modbus.h>
#include <ModbusSerial.h>

//Modbus slave address
const int SLAVE_ADDRESS = 1;

//Modbus Registers Offsets (0-9999)
const int SENSOR_IREG1 = 1;
const int SENSOR_IREG2 = 2;
const int SENSOR_IREG3 = 3;
const int SENSOR_IREG4 = 4;
//Used Pins
const int sensorPin = A0;

// ModbusSerial object
ModbusSerial mb;

long ts;

void setup() {
  // Config Modbus Serial (port, speed, byte format) 
  // 38400 was the default baud rate
  mb.config(&Serial, 19200, SERIAL_8N1);
  // Set the Slave ID (1-247)
  mb.setSlaveId(SLAVE_ADDRESS);

  // Add SENSOR_IREG register - Use addIreg() for analog Inputs
  mb.addIreg(SENSOR_IREG1);
  mb.addIreg(SENSOR_IREG2);
  mb.addIreg(SENSOR_IREG3);
  mb.addIreg(SENSOR_IREG4);
  
  ts = millis();
}

void loop() {
  mb.task();
  
  if (millis() > ts + 150) {
	  ts = millis();
	  mb.Ireg(SENSOR_IREG1, analogRead(sensorPin));
	  mb.Ireg(SENSOR_IREG2, analogRead(sensorPin));
	  mb.Ireg(SENSOR_IREG3, analogRead(sensorPin));
	  mb.Ireg(SENSOR_IREG4, analogRead(sensorPin));
  }  
}
