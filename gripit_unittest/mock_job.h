#pragma once

#include "job.h"

class MockJob : public Job {
public:
	MockJob();
	void run();
	int call_count;
};
