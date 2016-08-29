#include "gripit_immediate_job_runner.h"

void GripitImmediateJobRunner::run(Job* job) {
	job->run();
}