// stats.cpp
// Project UID 5366c7e2b77742d5b2142097e51561a5
#include "stats.h"
#include <cassert>
#include <vector>
#include <cmath>


using namespace std;

void bubbleSort(vector<double>& v);

vector<pair<double, int> > summarize(vector<double> v) {
	bubbleSort(v);
	v.push_back(v[v.size() - 1] + 1);
	vector<pair<double, int>> result;
	int count = 1;
	for (size_t i = 0; i < v.size() - 1; ++i) {
		if (v[i + 1] > v[i]) {
			result.push_back(make_pair(v[i], count));
			count = 1;
		}
		else
			count++;
	}
	return result;
}


int count(vector<double> v) {
	return v.size();
}


double sum(vector<double> v) {
	double total = 0;
	for (size_t i = 0; i < v.size(); ++i)
		total += v[i];
	return total;
}


double mean(vector<double> v) {
	return sum(v) / count(v);
}


double median(vector<double> v) {
	//bubbleSort(v);
	if (v.size() % 2 == 1)
		return v[(v.size() - 1) / 2];
	else
		return (v[(v.size()) / 2] + v[(v.size()) / 2 - 1]) / 2;
}


double mode(vector<double> v) {
	vector<pair<double, int>> stats = summarize(v);
	int count = 0;
	size_t which = 0;
	for (size_t i = 0; i < stats.size(); ++i) {
		if (stats[i].second > count) {
			count = stats[i].second;
			which = i;
		}
	}
	return stats[which].first;
}


double min(vector<double> v) {
	vector<pair<double, int>> stats = summarize(v);
	return stats[0].first;
}


double max(vector<double> v) {
	vector<pair<double, int>> stats = summarize(v);
	return stats[stats.size() - 1].first;
}


double stdev(vector<double> v) {
	double avg = mean(v);
	double se = 0;
	for (size_t i = 0; i < v.size(); ++i) {
		se += (v[i] - avg) * (v[i] - avg);
	}
	se = se / (v.size() - 1);
	se = sqrt(se);
	return se;
}


double percentile(vector<double> v, double p) {
	bubbleSort(v);
	if (p == 100)
		return v[v.size() - 1];
	double n = p * (v.size() - 1) / 100;
	double fractpart, intpart;
	fractpart = modf(n, &intpart);
	return v[intpart] + fractpart * (v[intpart + 1] - v[intpart]);
}

void bubbleSort(vector<double>& v) {
	for (size_t i = 0; i < v.size(); ++i) {
		for (size_t j = v.size() - 1; j > i; --j) {
			if (v[j] < v[j - 1]) {
				double temp = v[j];
				v[j] = v[j - 1];
				v[j - 1] = temp;
			}
		}
	}
}
