#include <functional>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>

template<class It, class Cmp>
void qsort(It first, It last, Cmp cmp) {
	if (first != last) {
		It left = first;
		It right = last;
		It pivot = left++;
		while (left != right) 
		{
			if (cmp(*left, *pivot)) 
			{
				++left;
			}
			else 
			{
				while ((left != --right) && cmp(*pivot, *right));
				std::swap(*left, *right);
			}
		}
		--left;
		std::swap(*first, *left);
		qsort(first, left, cmp);
		qsort(right, last, cmp);
	}
}


int main() 
{
	std::vector<int> vec;
	for (int i = 0; i < 30; ++i) vec.push_back(rand() % 100);

	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << '\n';
	
	qsort<std::vector<int>::iterator, std::less<int>>(vec.begin(), vec.end(), std::less<int>());
	
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << '\n';
	
	system("pause");
	return 0;
}
