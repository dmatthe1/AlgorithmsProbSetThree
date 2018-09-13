//Team C: Daniel Matthewson, Madeline Wilson, Morgan King
//CSCI 3322: Principles of Algorithms
//Problem Set Three: Radix Sort
//September 17th, 2017
//Pledged
#include<stable_sort>
#include<Math.h>
using namespace std;
template<typename T,typename K>
void radixSort(T begin,T end,K keyFunc) {
  //works for anything that you can break into digits
	int max = 0;
	T itr = begin;
	while(itr != end) {
		if (keyFunc(*itr) > max) {max = keyFunc(*itr)}
		itr++;
	}
	int numDigit = 0;
	int keytemp = max;
	while(keytemp >= 1)
		keytemp /= 10;
		numDigit += 1;
	}
	for(int i = 1; i <= numDigit; i++) {
		//Array<int> digits;
		Array<int> counts[10];
		T itr = begin;
		while(itr != end) {
			keyFunc(*itr);
			counts
			itr++
		}
	}
  //Starting with the least significant digit, sort the telements on that digit using a stable sort. Then go through the digits
    

}
