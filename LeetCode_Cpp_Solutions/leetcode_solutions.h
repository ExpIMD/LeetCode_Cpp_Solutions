#ifndef __LEETCODE_SOLUTIONS_
#define __LEETCODE_SOLUTIONS_

#include <optional>
#include <string>
#include <tuple>
#include <vector>

// Given a vector of integers <numbers> and an integer <target>
// Returns a tuple of two indices of elements in a vector whose sum equals the <target>
// Otherwise, returns a tuple of two zeros
std::tuple<size_t, size_t> two_sum(const std::vector<int>& numbers, int target);

// Given a sorted vector <vec> and a value <target>
// Returns the index of <target> in <vec> if it exists
// Otherwise, returns the index where <target> would theoretically be inserted to maintain sorted order
template<typename T> requires requires(T a, T b) { { a < b } -> std::convertible_to<bool>; }
size_t search_insert_position(const std::vector<T>& vec, T target) {
	size_t left = 0;
	size_t right = vec.size();
	// left and right are pointers to elements in the vector on both sides

	while (left < right) { // We will consider the range [left; right) to avoid value overflow
		size_t middle = (left + right) / 2;

		// For convenience, only the operator<() will be used
		// We shift the left and right pointers
		if (target < vec[middle]) right = middle;
		else if (vec[middle] < target) left = middle + 1;
		else return middle; // Found solution
	}
	return left; // Returns the index in the vector where the target would theoretically be positioned 
}

// Given a sorted vector <vec> and a value <target>
// Returns the index of <target> in <vec> if it exists
// Otherwise, returns -1
template<typename T> requires requires(T a, T b) { { a < b } -> std::convertible_to<bool>; }
std::optional<size_t> binary_search(const std::vector<T>& vec, T target) {
	size_t left = 0;
	size_t right = vec.size();
	// left and right are pointers to elements in the vector on both sides

	while (left < right) { // We will consider the range [left; right) to avoid value overflow
		size_t middle = (left + right) / 2;

		// For convenience, only the operator<() will be used
		// We shift the left and right pointers
		if (target < vec[middle]) right = middle;
		else if (vec[middle] < target) left = middle + 1;
		else return middle; // Found solution
	}
	return std::nullopt; // Returns std::nullopt if the target element is not found
}

// Given an integer <number>
// Returns the reversed <number> with preservation of sign
// Returns zero in case of value overflow
template<typename T> requires std::integral<T>
T reversed(T number) {
	T reversed{ 0 };

	while (number != 0) {
		T pop = number % 10; // Write down the last digit of the number

		// Checks for value overflow
		if (reversed > std::numeric_limits<T>::max() / 10 ||
			(reversed == std::numeric_limits<T>::max() / 10 && pop > std::numeric_limits<T>::max() % 10))
			return 0;
		if (reversed < std::numeric_limits<T>::min() / 10 ||
			(reversed == std::numeric_limits<T>::min() / 10 && pop < std::numeric_limits<T>::min() % 10))
			return 0;

		// Construct the reversed number and change the number
		reversed = reversed * 10 + pop;
		number /= 10;
	}
	return reversed; // Return the reversed number
}

// Given a string <line>
// Returns the length of the last word in <line>
size_t last_word_length(const std::string& line) {
	size_t length{ 0 };
	for (size_t i{ line.size() }; i-- > 0; ) { // This unusual construction is needed to avoid value overflow and 
		if (!std::isspace(line[i])) ++length;
		else if (length > 0) break; // Verifying whether a word has been seen before
	}
	return length;
}

#endif __LEETCODE_SOLUTIONS_
