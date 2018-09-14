#pragma once
#include <iterator>
#include <math.h>
#include <vector>
#include <stdio.h>
#include<algorithm>

using namespace std;

template<typename T, typename K> void bucketSort(T begin, T end, K keyFunc);
int bucket(double val, int length, double max);

template<typename T, typename K>
void bucketSort(T begin, T end, K keyFunc) {
	T itr = begin + 1;

	//find max value in array for bucket formula
	double max = keyFunc(*begin);
	while (itr < end) {
		if (keyFunc(*itr) > max) {
			max = keyFunc(*itr);
		}
		itr = itr + 1;
	}

	int numBuckets = end - begin;
	vector < vector<typename iterator_traits<T>::value_type >> buckets(numBuckets);
	itr = begin;

	//add elements to buckets
	while (itr < end) {
		buckets[bucket(keyFunc(*itr), numBuckets, max)].push_back(*itr);
		itr = itr + 1;
	}

	//sort individual buckets
	for (auto &v : buckets) {
		stable_sort(v.begin(), v.end(), [keyFunc](typename iterator_traits<T>::value_type a, typename iterator_traits<T>::value_type b) { return keyFunc(a) < keyFunc(b); });
	}

	//return elements to vector in order
	itr = begin;
	for (auto &v : buckets) {
		for (auto i : v) {
			*itr = i;
			itr = itr + 1;
		}
	}
}


//find bucket where value belongs
int bucket(double val, int length, double max) {
	return floor((val * length) / (max + 1));
}
