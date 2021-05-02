#include <iostream>
#include "tvector.h"
#include "tvector.cpp"
using namespace std;

int main() {
	tvector<int> v;
	v.push_back(6);
	v.push_back(7);
	cout<<v.at(0)+v.at(1)<<endl;
	cout<<v[0]+v[1]<<endl;
	v.pop_back();
	cout<<v[1]<<endl;

	v.pop_back();
	try {
		v.pop_back();
	} 
	catch(const char* ex) {
		cout<<ex;
	}
}