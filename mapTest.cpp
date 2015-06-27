#include <iostream>
#include <map>
#include <string>
using namespace std;

template <class T>
struct fun1{
	bool operator()(const T& val1, const T& val2)
	{
		return (val1 > val2);
	}
};

template <class T>
struct fun2{
	bool operator()(const T& val1, const T& val2)
	{
		return (val1 < val2);
	}
};


int main()
{
	////////////////////////////////////////////////////////
	//map的初始化，赋值，与遍历
	////////////////////////////////////////////////////////
	cout << "1. map的初始化，赋值，与遍历" << endl;
	map<int, char> intToChar1;
	//intToChar1 插入元素的三种方法：
	intToChar1[1] = 'a';
	intToChar1[3] = 'b';
	intToChar1[2] = 'c';

	intToChar1.insert(pair <int, char>(4, 'd'));
	intToChar1.insert(pair <int, char>(15, 'e'));

	intToChar1.insert(make_pair(6, 'f'));
	intToChar1.insert(make_pair(7, 'g'));

	cout << intToChar1.cbegin()->first << endl;
	//cout << intToChar1.cend()->first << endl;

	//intToChar2的初始化
	map<int, char> intToChar2(intToChar1); 

	//intToChar2的遍历, 以及元素的取出
	cout << "print the map intToChar2: " << endl;
	for (auto iter = intToChar2.cbegin(); iter != intToChar2.cend(); iter++)
		cout << iter->first << ": " << iter->second << endl;
	//把intToChar2的部分赋值给intToChar3;
	map<int, char>::iterator iter = intToChar2.begin();
	for (; iter != intToChar2.end(); iter++)
	{
		if (iter->first == 6)
			break;
	}
	map <int, char> intToChar3(intToChar2.begin(), iter);
	//intToChar3的遍历
	cout << "print the map inToChar3(部分赋值): " << endl;
	for (auto iter = intToChar3.cbegin(); iter != intToChar3.cend(); ++iter)
	{
		cout << iter->first << ": " << iter->second << endl;
	}

	//修改intToChar1的特定键-值
	for (map<int,char>::iterator iter = intToChar1.begin(); iter != intToChar1.end(); ++iter)
	{
		//if (iter->second == 'c')
		//	iter->first = 30;
		if (iter->first == 3)
			iter->second = 'z';
	}

	cout << "intToChar1修改键值后： " << endl;
	for (auto iter = intToChar1.cbegin(); iter != intToChar1.cend(); ++iter)
		cout << iter->first << ": " << iter->second << endl;
	cout << endl;
	////////////////////////////////////////////////////////
	//map的swap函数用法，swap用来交换两个map的所有键-值对
	////////////////////////////////////////////////////////
	cout << "2. map的swap函数用法" << endl;
	map <int, int> m1, m2, m3;

	m1.insert(pair <int, int>(1, 10));
	m1.insert(pair <int, int>(2, 20));
	m1.insert(pair <int, int>(3, 30));

	m2.insert(pair <int, int>(10, 100));
	m2.insert(pair <int, int>(20, 200));

	m3.insert(pair <int, int>(30, 300));
	map <int, int>::iterator m1_Iter;
	cout << "The original map m1 is:";
	for (m1_Iter = m1.begin(); m1_Iter != m1.end(); m1_Iter++)
		cout << " " << m1_Iter->second;
	cout << "." << endl;
	// This is the member function version of swap
	//m2 is said to be the argument map; m1 the target map
	m1.swap(m2);
	cout << "After swapping with m2, map m1 is:";
	for (m1_Iter = m1.begin(); m1_Iter != m1.end(); m1_Iter++)
		cout << " " << m1_Iter->second;
	cout << "." << endl;
	cout << "After swapping with m2, map m2 is:";
	for (m1_Iter = m2.begin(); m1_Iter != m2.end(); m1_Iter++)
		cout << " " << m1_Iter->second;
	cout << "." << endl;
	// This is the specialized template version of swap
	swap(m1, m3);
	cout << "After swapping with m3, map m1 is:";
	for (m1_Iter = m1.begin(); m1_Iter != m1.end(); m1_Iter++)
		cout << " " << m1_Iter->second;
	cout << "." << endl << endl;


	////////////////////////////////////////////////////////
	//map的查找键-值对
	////////////////////////////////////////////////////////
	cout << "3. map查找键-值对" << endl;
	cout << "intToChar1遍历" << endl;
	for (map<int, char>::const_iterator iter = intToChar1.cbegin(); iter != intToChar1.cend(); iter++)
	{
		cout << iter->first << ": " << iter->second << endl;
	}
	
	map<int, char>::const_iterator iter1;
	cout << "please input the key to find (-1 to quit): ";
	int num;
	cin >> num;
	while (num != -1)
	{
		iter1 = intToChar1.find(num);
		if (iter1 != intToChar1.cend())
			cout << "Key " << iter1->first << " points to " << iter1->second << endl;
		else
			cout << "Key " << num << " not in map" << endl;
		cout << "please input the key to find (-1 to quit): ";
		cin >> num;
	}
	cout << endl;
	////////////////////////////////////////////////////////
	//multimap的查找键-值对
	////////////////////////////////////////////////////////
	cout << "4. multimap查找键-值对" << endl;
	multimap <char, string> mcs;
	//mcs['a'] = "apple"; //不能这样为multimap赋值
	mcs.insert(pair<char, string>('a', "apple"));
	mcs.insert(make_pair('b', "bob"));
	mcs.insert(make_pair('b', "book"));
	mcs.insert(make_pair('b', "book"));//可以储存同样的键值对
	mcs.insert(make_pair('c', "charlie"));
	mcs.insert(make_pair('c', "cake"));
	mcs.insert(make_pair('d', "dark"));
	mcs.insert(make_pair('e', "echo"));

	cout << "multimap的遍历" << endl;
	for (auto iter = mcs.cbegin(); iter != mcs.cend(); ++iter)
	{
		cout << iter->first << ": " << iter->second << endl;
	}

	multimap<char, string> ::const_iterator iter2;
	int howMany;
	cout << "input the key to find(q to quit): ";
	char key;
	cin >> key;
	while (key != 'q')
	{
		iter2 = mcs.find(key);
		if (iter2 != mcs.cend())
		{
			howMany = mcs.count(key);//在multimap中有多少个key?
			for (int i = 0; i < howMany; i++)
			{
				cout << iter2->first << ": " << iter2->second << endl;
				iter2++;
			}
		}
		else
			cout << key << " was not found" << endl;
		cout << "input the key to find(q to quit): ";
		cin >> key;
	} 
	////////////////////////////////////////////////////////
	//multimap的erase
	////////////////////////////////////////////////////////
	cout << "4. multimap 删除键-值对" << endl;
	cout << "mcs有" << mcs.size() << "个键值对" << endl;
	for (auto iter = mcs.cbegin(); iter != mcs.cend(); ++iter)
	{
		cout << iter->first << ": " << iter->second << endl;
	}

	cout << "删除一个键值对(d)" << endl;
	mcs.erase('d');
	cout << "print the mcs:" << endl;
	for (auto iter = mcs.cbegin(); iter != mcs.cend(); ++iter)
	{
		cout << iter->first << ": " << iter->second << endl;
	}

	cout << "删除多个键值对(b)" << endl;
	mcs.erase(mcs.lower_bound('b'), mcs.upper_bound('b'));

	cout << "print the mcs:" << endl;
	for (auto iter = mcs.cbegin(); iter != mcs.cend(); ++iter)
	{
		cout << iter->first << ": " << iter->second << endl;
	}

	cout << endl;

	////////////////////////////////////////////////////////
	//multimap的自定义排序谓词
	////////////////////////////////////////////////////////
	cout << "5. map的自定义排序谓词" << endl;
	cout << "intToChar1的原始数据" << endl;
	for (auto iter = intToChar1.cbegin(); iter != intToChar1.cend(); ++iter)
	{
		cout << iter->first << ", " << iter->second << endl;
	}

	cout << "使用fun1来初始化intToChar4 (ReverseSort排序): " << endl;
	map< int, char, fun1<int> > intToChar4(intToChar1.cbegin(), intToChar1.cend());

	for (auto iter = intToChar4.cbegin(); iter != intToChar4.cend(); ++iter)
	{
		cout << iter->first << ", " << iter->second << endl;
	}

	cout << "使用fun2来初始化intToChar5 (return val1 < val2, 默认的排序方法): " << endl;
	map< int, char, fun2<int> > intToChar5(intToChar1.cbegin(), intToChar1.cend());

	for (auto iter = intToChar5.cbegin(); iter != intToChar5.cend(); ++iter)
	{
		cout << iter->first << ", " << iter->second << endl;
	}
}
