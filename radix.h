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
  vector<typename std::iterator_traits<T>::value_type> output (end - begin);
  int max = 0;
	for (auto iter = begin; iter != end; iter++) {
		if (keyFunc(*iter) > max) {max = keyFunc(*iter);}
	}
  max = digitCount(max);

  //looping through until all digits are accounted for
  for (int place = 1; place <= max; place++) {
    //initialize count vector of size 10
    vector<int> count (10, 0);

    for (auto iter = begin; iter < end; iter++) {
      //increment count for digit
      count[getDigit(keyFunc(*iter), place)]++;
    }

    //sum up the count vector contents
    for (int i = 1; i < count.size(); i++) {
      count[i] = count[i] + count[i - 1];
    }

    //update output vector
    for (auto iter = end - 1; iter >= begin; iter--) {
      int dig = getDigit(keyFunc(*iter), place);
      count[dig]--;
      int index = count[dig];
      output[index] = *(iter);
    }

    //update original vector with sorted output data
    for (int count = 0; count < (end - begin); count++) {
      *(begin + count) = output[count];
    }
  }
}
