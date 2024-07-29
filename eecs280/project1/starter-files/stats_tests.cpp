/* stats_tests.cpp
 *
 * Unit tests for the simple statistics library
 * Project UID 5366c7e2b77742d5b2142097e51561a5
 *
 * EECS 280 Project 1
 *
 * Protip #1: Write tests for the functions BEFORE you implement them!  For
 * example, write tests for median() first, and then write median().  It sounds
 * like a pain, but it helps make sure that you are never under the illusion
 * that your code works when it's actually full of bugs.
 *
 * Protip #2: Instead of putting all your tests in main(),  put each test case
 * in a function!
 */


#include "stats.h"
#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>
using namespace std;

void test_sum_small_data_set();
// Add prototypes for you test functions here.
void general_test();
void special_test();

int main() {
  test_sum_small_data_set();
  // Call your test functions here
  general_test();
  special_test();
  return 0;
}

void test_sum_small_data_set() {
  cout << "test_sum_small_data_set" << endl;

  vector<double> data;
  data.push_back(1);
  data.push_back(2);
  data.push_back(3);

  assert(sum(data) == 6);

  cout << "PASS!" << endl;
}

// Add the test function implementations here.

void general_test() {
	vector<double> data;
	data.push_back(1);
	data.push_back(2);
	data.push_back(3);
	data.push_back(4);
	assert(count(data) == 4);
	cout << "'count' PASS" << endl;
	assert(mean(data) == 2.5);
	cout << "'mean' PASS" << endl;
	assert(median(data) == 2.5);
	cout << "'median' PASS" << endl;
	assert(mode(data) == 1);
	cout << "'mode' PASS" << endl;
	assert(max(data) == 4);
	cout << "'max' PASS" << endl;
	assert(min(data) == 1);
	cout << "'min' PASS" << endl;
	assert(stdev(data) > 1.29099);
	assert(stdev(data) < 1.29100);
	cout << "'stdev' PASS" << endl;
	assert(percentile(data, 0) == 1);
	cout << "'percentile' PASS" << endl;
	assert(summarize(data).size() == 4);
	cout << "'summarize' PASS" << endl;
}

void special_test() {
	vector<double> data;
	data.push_back(1);
	data.push_back(1);
	data.push_back(1);
	data.push_back(1);
	assert(count(data) == 4);
	cout << "'count' PASS" << endl;
	assert(mean(data) == 1);
	cout << "'mean' PASS" << endl;
	assert(median(data) == 1);
	cout << "'median' PASS" << endl;
	assert(mode(data) == 1);
	cout << "'mode' PASS" << endl;
	assert(max(data) == 1);
	cout << "'max' PASS" << endl;
	assert(min(data) == 1);
	cout << "'min' PASS" << endl;
	assert(stdev(data) == 0);
	cout << "'stdev' PASS" << endl;
	assert(percentile(data, 0) == 1);
	cout << "'percentile' PASS" << endl;
	assert(summarize(data).size() == 1);
	cout << "'summarize' PASS" << endl;
}
