#pragma once

#include "gripit_job_runner.h"
#include <vector>

class MockGripitJobRunner : public GripitJobRunner {
public:
	MockGripitJobRunner();
	~MockGripitJobRunner();
	void run(Job* job);
	std::vector<Job*> *run_params;
};
