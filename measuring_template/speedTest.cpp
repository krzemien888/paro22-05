#include <chrono>
#include <iostream>
#include <vector>
#include <time.h>
#include <cstdlib>
#include <set>
#include <algorithm>


using namespace std;

int numOfUnique1(vector<int> const &v)
{
	auto s = set<int>(begin(v), end(v));
	return s.size();
}

int numOfUnique2(vector<int> v)
{
	sort(begin(v), end(v));
	v.erase(unique(begin(v), end(v)), end(v));
	return v.size();
}

int main()
{
	srand(time(NULL));
	vector<int> v;
	vector<int> resultsSet;
	vector<int> resultsSort;	


	for(int i = 0; i< 10000; ++i)
		v.push_back(i);
	
	auto t1 = chrono::high_resolution_clock::now();
	numOfUnique1(vector<int>(v));
	auto t2 = chrono::high_resolution_clock::now();
	auto time = duration_cast<duration<int>>(t2-t1);
	cout << "1st: " << time.count() << endl;

	t1 = chrono::high_resolution_clock::now();
	numOfUnique2(vector<int>(v));
	t2 = chrono::high_resolution_clock::now();
	time = duration_cast<duration<int>>(t2-t1);
	cout << "2nd: " << time.count() << endl;



	return 0;
}
