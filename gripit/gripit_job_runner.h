#pragma once

#include "job.h"

class GripitJobRunner {
public:
	virtual void run(Job *job) = 0;
};
