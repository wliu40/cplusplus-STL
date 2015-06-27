
//http://bbs.csdn.net/topics/340143411
// sort algorithm example

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool myfunction(int i, int j) { return (i<j); }

struct myclass {
bool operator() (int i, int j) { return (i<j); }
} myobject;

template <class T>
void print(vector<T> myvector)
{
	// print out content:
	vector<T>::iterator it;
	cout << "myvector contains:";
	for (it = myvector.begin(); it != myvector.end(); ++it)
		cout << " " << *it;
	cout << endl;
}
bool myCompare(const string &s1, const string &s2)
{
	int result = s1.compare(s2);
	if (result != 1)
		return false;
	else
		return true;
}


int main() {
int myints[] = { 32, 71, 12, 45, 26, 80, 53, 33 };
vector<int> myvector(myints, myints + 8);              // 32 71 12 45 26 80 53 33
print<int>(myvector);


// using default comparison (operator <):
sort(myvector.begin(), myvector.begin() + 4);           //(12 32 45 71)26 80 53 33
print<int>(myvector);

// using function as comp
sort(myvector.begin() + 4, myvector.end(), myfunction); // 12 32 45 71(26 33 53 80)
print<int>(myvector);

// using object as comp
myclass mc;
sort(myvector.begin(), myvector.end(), mc);     //(12 26 32 33 45 53 71 80)
print<int>(myvector);

vector<string> s{ "123", "120", "12", "134" };

sort(s.begin(), s.end());
print<string>(s);

sort(s.begin(), s.end(), myCompare);
print <string>(s);

cout << endl;

return 0;
}

