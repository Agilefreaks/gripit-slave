#pragma once

#include "gripit_job_runner.h"

class GripitImmediateJobRunner : public GripitJobRunner {
public:
	void run(Job *job);
};

