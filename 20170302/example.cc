///
/// @file    example.cc
/// @author  lemon(haohb13@gmail.com)
/// @date    2017-03-02 20:54:14
///


#include <vector>
#include <algorithm>
#include <iostream>

struct Sum
{
	Sum(): sum{0} { }
	void operator()(int n) { sum += n; }
	int sum;
};

int main()
{
	std::vector<int> nums{3, 4, 2, 8, 15, 267};

	auto print = [](const int& n) { std::cout << " " << n; };

	std::cout << "before:";
	std::for_each(nums.begin(), nums.end(), print);
	std::cout << '\n';

	std::for_each(nums.begin(), nums.end(), [](int &n){ n++; });

	// calls Sum::operator() for each number  
	Sum s = std::for_each(nums.begin(), nums.end(), Sum());

	std::cout << "after: ";
	std::for_each(nums.begin(), nums.end(), print);
	std::cout << '\n';
	std::cout << "sum: " << s.sum << '\n';
}
