//Team C: Daniel Matthewson, Madeline Wilson, Morgan King
//CSCI 3322: Principles of Algorithms
//Problem Set Three: Radix Sort
//September 17th, 2017
//Pledged

#include<algorithm>
#include<vector>

using namespace std;

//Helper Functions
//Returns the number of digits in an integer
int digitCount(int num) {
  int digits = 0;
  while (num > 0) {
    num = num/10;
    digits++;
  }
  return digits;
}

//Returns the digit of a num in the passed-in place
int getDigit(int num, int place) {
  while (place > 1) {
    place--;
    num = num/10;
  }
  return num%10;
}

template<typename T, typename K>
void radixSort(T begin, T end, K keyFunc) {
  //initializations for output and max digit count
  vector<T> output (end - begin);
  int max = digitCount(keyFunc(*begin));

  //looping through until all digits are accounted for
  for (int place = 0; place <= max; place++) {
    //initialize count vector of size 10
    vector<int> count (10, 0);

    for (auto iter = begin; iter < end; iter++) {
      //increment count for digit
      count[getDigit(keyFunc(*iter), place)]++;
    }

    //sum up the count vector contents
    for (int i = 1; i < count.size() - 1; i++) {
      count[i] = count[i] + count[i - 1];
    }

    //update output vector
    for (auto iter = end; iter >= begin; iter--) {
      output[count[getDigit(keyFunc(*iter), place)]--] = iter;
    }

    //update original vector with sorted output data
    for (int count = 0; count < (end - begin); count++) {
      *(begin + count) = *(output[count]);
    }
  }
}

/**
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
**/
