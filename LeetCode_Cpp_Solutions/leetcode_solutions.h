#ifndef __LEETCODE_SOLUTIONS_
#define __LEETCODE_SOLUTIONS_

#include <tuple>
#include <vector>
#include <string>

// Given a vector of integers <numbers> and an integer <target>
// Returns a tuple of two indices of elements in a vector whose sum equals the <target>
// Otherwise, returns a tuple of two zeros
std::tuple<size_t, size_t> two_sum(const std::vector<int>& numbers, int target);

// Given a sorted vector <vec> and a value <target>
// Returns the index of <target> in <vec> if it exists
// Otherwise, returns the index where <target> would theoretically be inserted to maintain sorted order
template<typename T> requires requires(T a, T b) { { a < b } -> std::convertible_to<bool>; }
size_t binary_search(const std::vector<T>& vec, T target) {
	int left = 0;
	int right = vec.size() - 1;
	// Left and Right are pointers to elements in the vector on both sides

	while (left <= right) {
		int middle = (left + right) / 2;

		// For convenience, only the operator<() will be used
		// We shift the left and right pointers
		if (target < vec[middle]) right = middle - 1;
		else if (vec[middle] < target) left = middle + 1;
		else return middle; // Exist solution
	}
	return left; // Returns the index in the vector where the target would theoretically be positioned 
}




#endif __LEETCODE_SOLUTIONS_
