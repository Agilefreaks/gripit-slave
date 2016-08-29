#include <iostream>

#include "main.h"
#include "mocks.h"
#include "gripit_task_tests.h"
#include "read_sensors_job_tests.h"
#include "gripit_immediate_job_runner_tests.h"
#include "address_auto_assignment_job_tests.h"
#include "gripit_address_generator_tests.h"

using namespace std;

int main(int argc, char **argv) {
	initialize_mocks();
	run_tests();
	cout << "All test have passed\r\n";
	system("pause");
}

void run_tests() {
	(new GripitTaskTests())->run_tests();
	(new ReadSensorsJobTests())->run_tests();
	(new GripitImmediateJobRunnerTests())->run_tests();
	(new AddressAutoAssignmentJobTests())->run_tests();
	(new GripitAddressGeneratorTets())->run_tests();
}