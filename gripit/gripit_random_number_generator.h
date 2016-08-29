#pragma once

class GripitRandomNumberGenerator {
public:
	virtual unsigned int generate(unsigned int max_value) = 0;
};