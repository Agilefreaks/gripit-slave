#pragma once

#include <vector>
#include <assert.h>
#include "helpers.h"

template <class T> class TestSuite {
public:
	TestSuite();
	~TestSuite();
	virtual void setup();
	virtual void teardown();
	virtual T* get_context();

	void run_tests();

protected:
	std::vector<void(*)(T* context)> *tests;

private:
	void run_test(void(*test)(T* context));	
};

template <class T> TestSuite<T>::TestSuite<T>() {
	this->tests = new std::vector<void(*)(T* context)>();
}

template <class T> TestSuite<T>::~TestSuite<T>() {
	delete this->tests;
}

template <class T> void TestSuite<T>::setup() {
}

template <class T> void TestSuite<T>::teardown() {
}

template <class T> void TestSuite<T>::run_test(void(*test)(T* context)) {
	(*test)(this->get_context());
}

template <class T> T* TestSuite<T>::get_context() {
	return static_cast<T*>(this);
}

template <class T> void TestSuite<T>::run_tests() {
	for (int index = 0; index < tests->size(); index++) {
		this->setup();
		this->run_test(tests->at(index));
		this->teardown();
	}
}