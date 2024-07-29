// main.cpp
// Project UID 5366c7e2b77742d5b2142097e51561a5

#include "stats.h"
#include "p1_library.h"
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <limits>

using namespace std;

int main() {
	string filename;
	string colname;
	cout << "enter a filename" << endl;
	cin >> filename;
	cout << "enter a column name" << endl;
	cin >> colname;
	cout << "reading column " << colname << " from " << filename << endl;
	vector<double> vec = extract_column(filename, colname);
	vector<pair<double, int>> summary = summarize(vec);
	cout << "Summary (value: frequency)" << endl;
	for (size_t i = 0; i < summary.size(); ++i) {
		cout << summary[i].first << ": " << summary[i].second << endl;
	}
	cout << endl;
	cout << "count = " << count(vec) << endl;
	cout << "sum = " << sum(vec) << endl;
	cout << "mean = " << mean(vec) << endl;
	cout << "stdev = " << stdev(vec) << endl;
	cout << "median = " << median(vec) << endl;
	cout << "mode = " << mode(vec) << endl;
	cout << "min = " << min(vec) << endl;
	cout << "max = " << max(vec) << endl;
	cout << "  0th percentile = " << percentile(vec, 0) << endl;
	cout << " 25th percentile = " << percentile(vec, 25) << endl;
	cout << " 50th percentile = " << percentile(vec, 50) << endl;
	cout << " 75th percentile = " << percentile(vec, 75) << endl;
	cout << "100th percentile = " << percentile(vec, 100) << endl;

	return 0;
}