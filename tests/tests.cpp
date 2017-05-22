#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>
#include <vector>

using namespace std;

int main(int argc, char** args)
{
	vector<int> v;

	auto t1 = chrono::high_resolution_clock::now();

	for(int i = 0; i < atoi(args[1]); ++i)
		v.push_back(i);	
	auto t2 = chrono::high_resolution_clock::now();
	
	cout << "czas: " << chrono::duration_cast<chrono::duration<double>>(t2-t1).count() << endl;

	return 0;
}
