#pragma once

class GripitSensorReader
{
public:
	GripitSensorReader();
	~GripitSensorReader();

	virtual int read_sensor(char sensor) = 0;
};