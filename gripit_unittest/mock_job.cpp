#include "mock_job.h"

MockJob::MockJob() {
	this->call_count = 0;
}

void MockJob::run() {
	this->call_count++;
}