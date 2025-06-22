#include <iostream>


#include "leetcode_solutions.h"

int main() {
	std::vector<std::string> vec{ "aac" };
	auto res = longest_common_prefix_sort(vec);
	res += "D";
	std::cout << res;
	std::cout << vec[0];


	return 1;
}