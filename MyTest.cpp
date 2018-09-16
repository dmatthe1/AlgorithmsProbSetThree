#include<fstream>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<string>
#include<vector>
#include<iostream>

#include "radix.h"

using std::ofstream;
using std::endl;
using std::clock;
using std::vector;
using std::string;
using std::cout;
using std::endl;

int main() {
  double test = std::rand();
  cout<<test<<"\n";
  vector<int> nums1(10);
	for(auto iter = nums1.begin(); iter != nums1.end(); iter++) *iter = std::rand();
  cout<<"Begin: "<<*(nums1.begin())<<" End: "<<*(nums1.end())<<"\n";
  radixSort(nums1.begin(),nums1.end(),[] (int i) {return i;});
}
