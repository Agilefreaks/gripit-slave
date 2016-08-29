#include "gripit_immediate_job_runner_tests.h"
#include "mock_job.h"

void run_always_executes_the_given_job_immediately(GripitImmediateJobRunnerTests* context) {
	MockJob *mock_job = new MockJob();
	context->gripit_immediate_job_runner->run(mock_job);

	assert(mock_job->call_count == 1);
}

GripitImmediateJobRunnerTests::GripitImmediateJobRunnerTests() {
	this->tests->push_back(run_always_executes_the_given_job_immediately);
}

void GripitImmediateJobRunnerTests::setup() {
	this->gripit_immediate_job_runner = new GripitImmediateJobRunner();
}

void GripitImmediateJobRunnerTests::teardown() {
	delete this->gripit_immediate_job_runner;
}