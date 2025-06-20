#include <iostream>
#include <vector>

#include "leetcode_solutions.h"

int main() {

	std::vector<int> vec{ -2, 0, 1, 4, 7 };
	std::cout << std::boolalpha << binary_search(vec, 7).has_value();

	return 1;
}