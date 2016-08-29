#include "mock_gripit_job_runner.h"

MockGripitJobRunner::MockGripitJobRunner() {
	this->run_params = new std::vector<Job*>();
}

MockGripitJobRunner::~MockGripitJobRunner() {
	delete this->run_params;
}

void MockGripitJobRunner::run(Job *job) {
	this->run_params->push_back(job);
}
