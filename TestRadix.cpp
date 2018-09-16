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

struct Stuff {
	int key;
	string str;
	bool operator==(const Stuff &o) const {
		return key==o.key && str==o.str;
	}
};

int main(int argc,char** argv) {
	ofstream out("time.txt");
	std::srand(42);
	// Make ints
	vector<int> nums1(100000000);
	for(auto iter=nums1.begin(); iter!=nums1.end(); ++iter) *iter = std::rand();
	vector<int> nums2(nums1);
	// Make strings
	vector<Stuff> strings1(1000000);
	for(auto iter=strings1.begin(); iter!=strings1.end(); ++iter) {
		iter->key = std::rand();
		for(int i=0; i<6; ++i) iter->str += (char)('a'+rand()%26);
	}
	vector<Stuff> strings2(strings1);

	cout << "Start timing." << endl;
	double start = clock();
	radixSort(nums1.begin(),nums1.end(),[] (int i) {return i;});
	radixSort(strings1.begin(),strings1.end(),[] (const Stuff &s) { return s.key; });
	out << (clock()-start)/CLOCKS_PER_SEC << endl;
	out.close();
	// check
	cout << "Checking results." << endl;
	std::stable_sort(nums2.begin(),nums2.end());
	std::stable_sort(strings2.begin(),strings2.end(),[] (const Stuff &s1,const Stuff &s2) { return s1.key<s2.key; });
	if(nums1==nums2 && strings1==strings2) return 0;
	else return -1;
}
