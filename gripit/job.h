#pragma once

class Job {
public:
	Job();
	~Job();

	virtual void run() = 0;
};
