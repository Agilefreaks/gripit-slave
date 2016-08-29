#pragma once

#include "gripit_immediate_job_runner.h"
#include "test_suite.h"

class GripitImmediateJobRunnerTests : public TestSuite<GripitImmediateJobRunnerTests> {
public:	
	GripitImmediateJobRunnerTests();
	void setup();
	void teardown();
	GripitImmediateJobRunner *gripit_immediate_job_runner;
};
