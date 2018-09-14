#include<algorithm>
#include<Math.h>

using namespace std;

template<typename T, typename K>
void radixSort(T begin, T end, K keyFunc) {
	//works for anything that you can break into digits
	int max = 0;
	T itr = begin;
	while (itr < end) {
		if (keyFunc(*itr) > max) { max = keyFunc(*itr); }
		itr++;
	}
	int numDigit = 0;
	int keytemp = max;
	while (keytemp >= 1)
		keytemp /= 10;
	numDigit ++;

	for (int i = 0; i < numDigit; i++) {
		int counts[10];
		T itr = begin;
		const int n = (end - begin);
		T newOrder[n];

		//check last sigfig 
		while (itr < end) {
			int key = (int)(keyFunc(*itr) / pow(10, i)) % 10;
			counts[key]++;
			itr++;
		}

		//calculate start indices
		for (int j = 1; j < 10; j++)
			count[j] += count[j - 1];

		//place in order in newOrder
		itr = end-1;
		while (itr > begin) {
			int key = (int) (keyFunc(*itr) / pow(10, i)) % 10;
			newOrder[count[key]] = itr;
			count[key]--;
			itr--;
		}

		itr = begin;
		for (int j = 0; j < newOrder.length(); j++) {
			itr = newOrder[j];
			itr++;
		}
	}
//Starting with the least significant digit, sort the telements on that digit using a stable sort. Then go through the digits


}

