#include "leetcode_solutions.h"
#include <unordered_map>

// Given a vector of integers <numbers> and an integer <target>
// Returns a tuple of two indices of elements in a vector whose sum equals the <target>
// If there is no solution, then returns a tuple of two zeros
std::tuple<size_t, size_t> two_sum(const std::vector<int>& numbers, int target) {
	// Let target be the sum of the main and rest parts.

	std::unordered_map<int, size_t> mappping;
	// Define a mapping from the rest part to the index of the main part in the vector.

	for (size_t i{ 0 }; i < numbers.size(); ++i) { // We will iterate through all elements in the vector and compute the current rest part
		int rest_part = target - numbers[i];

		if (mappping.count(rest_part) > 0) return std::make_tuple(mappping[rest_part], i); // If an entry for the current rest part already exists in mapping, then the result is found!

		mappping[numbers[i]] = i; // Otherwise, we add a new entry for the current main part to mapping.
	}

	return std::make_tuple(0, 0); // No solution
}