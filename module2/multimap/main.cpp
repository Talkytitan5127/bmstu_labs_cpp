#include <map>
#include <iostream>
#include <string>
#include <algorithm>

#define CHECK

#ifdef CHECK
#include "TMultimap.h"

template<class K, class T>
using map = TMultimap<K, T>;

#else

template<class K, class T>
using map = std::multimap<K, T>;

#endif // CHECK


#define assert(X) { \
	if(!(X)) {\
		std::cout << "see function:'" << __FUNCTION__ << "' line: " << __LINE__ << std::endl;\
		std::cout << "condition :'" << #X << " is FALSE" << std::endl;\
		throw std::logic_error(#X); \
	}\
}

int main()
{
	{
		map<std::string, std::string> m;
		assert(m.empty());

		m.insert(std::make_pair("a", "1"));
		m.insert(std::make_pair("b", "2"));
		m.insert(std::make_pair("c", "3"));
		m.insert(std::make_pair("c", "3.1"));
		
		assert(m.size() == 4);

		auto m1 = m;
		assert(m.find("b")->second == "2");

		m1.clear();
		assert(m1.empty());

		m1.swap(m);
		assert(m.empty());
		assert(m1.size() == 4);

		assert(m1.find("d") == m1.end());
		assert(m1.find("a")->first == "a");
		assert(m1.find("a")->second == "1");

		for (auto it = m1.begin(); it != m1.end(); ++it)
		{
			std::cout << it->first << " " << it->second << std::endl;
		}

		auto it = m1.begin();
		it++;
		m1.erase(it);
		assert(m1.size() == 3);
		m1.erase("c");



		assert(m1.size() == 1);
		for (auto it = m1.begin(); it != m1.end(); ++it)
		{
			std::cout << it->first << " " << it->second << std::endl;
		}
		
		return 0;
	}
}
