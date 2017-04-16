#include <iostream>
#include <map>
#include <string>
#include "TMultimap.h"

using namespace std;

int main()
{
	
	TMultimap<string, int> mymap();

	TMultimap<int, string> map2{ {2, "ab"}, {10, "cd"}, {3, "pasha"}, {2, "qwer"}, {5, "lol"} };
	
	cout << "---MAP--2---\n";
	map2.Print();

	cout << "------------\n";

	auto p = map2.end();
	for (auto it = map2.begin(); it != map2.end(); ++it)
	{
		cout << (*it).first << " => " << (*it).second << '\n';
	}

	auto el = map2.Find(100);
	if (el == map2.end())
		cout << "Didn't find\n";

	cout << "---------\n";

	TMultimap<int, string> map3;

	map3 = map2;
	cout << "---MAP--3--\n";
	map3.Print();

	cout << "----------\n";

	map3.Insert(std::pair<int, string>(4, "four"));

	auto pEl = map3.Find(2);
	
	cout << "---MAP--3--\n";
	map3.Print();

	cout << "------\n";

	cout << "iterator: \n" << (*pEl).first << " => " << (*pEl).second << '\n';

	map3.Erase(pEl);
	cout << "after erase map3\n";
	
	cout << "---MAP--2--\n";
	map2.Print();
	
	cout << "---MAP--3--\n";
	map3.Print();
	
	cout << "------\n";

	cout << "iterator: \n" << (*pEl).first << " => " << (*pEl).second << '\n';
	
	cout << "before swap\n";
	cout << "---MAP--3--\n";
	map3.Print();

	cout << "---MAP--2--\n";
	map2.Print();

	map3.Swap(map2);
	cout << "after swap\n";
	
	cout << "---MAP--3--\n";
	map3.Print();

	cout << "---MAP--2--\n";
	map2.Print();

	TMultimap<string, int> newmap;
	newmap.Insert(std::make_pair("pop", 10));
	newmap.Insert(std::make_pair("aba", 5));
	newmap.Insert(std::make_pair("fal", 33));
	newmap.Insert(std::make_pair("aba", 86));
	newmap.Insert(std::make_pair("geg", 1));
	newmap.Insert(std::make_pair("aba", 100));

	cout << "---newmap----\n";
	newmap.Print();

	cout << "aba = " << newmap.TCount("aba") << '\n';


	TMultimap<char, int> mymultimap;

	mymultimap.Insert(std::make_pair('a', 10));
	mymultimap.Insert(std::make_pair('b', 121));
	mymultimap.Insert(std::make_pair('c', 1001));
	mymultimap.Insert(std::make_pair('c', 2002));
	mymultimap.Insert(std::make_pair('d', 11011));
	mymultimap.Insert(std::make_pair('e', 44));

	auto itlow = mymultimap.Lower_bound('b');  
	auto itup = mymultimap.Upper_bound('d');   

	for (auto it = itlow; it != itup; ++it)
		std::cout << (*it).first << " => " << (*it).second << '\n';
	

	TMultimap<char, int> mymm;

	mymm.Insert(std::pair<char, int>('a', 10));
	mymm.Insert(std::pair<char, int>('b', 20));
	mymm.Insert(std::pair<char, int>('b', 30));
	mymm.Insert(std::pair<char, int>('b', 40));
	mymm.Insert(std::pair<char, int>('c', 50));
	mymm.Insert(std::pair<char, int>('c', 60));
	mymm.Insert(std::pair<char, int>('d', 60));

	std::cout << "mymm contains:\n";
	for (char ch = 'a'; ch <= 'd'; ch++)
	{
		auto ret = mymm.Equal_range(ch);
		std::cout << ch << " =>";
		for (auto it = ret.first; it != ret.second; ++it)
			std::cout << ' ' << (*it).second;
		std::cout << '\n';
	}
	
	TMultimap<char, int> m4(mymm);
	
	cout << "--mymm--\n";
	mymm.Print();

	cout << "---m4---\n";
	m4.Print();
	
	system("pause");
	return 0;
}
