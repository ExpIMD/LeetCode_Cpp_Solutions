#ifndef __LEETCODE_SOLUTIONS_
#define __LEETCODE_SOLUTIONS_

#include <optional>
#include <unordered_map>
#include <string>
#include <tuple>
#include <vector>

// Given a vector of integers <numbers> and an integer <target>
// Returns a tuple of two indices of elements in a vector whose sum equals the <target>
// Otherwise, returns a tuple of two zeros
template<typename T> requires std::integral<T>
std::tuple<size_t, size_t> two_sum(const std::vector<T>& numbers, const T& target) {
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
size_t last_word_length(const std::string& line);

// Given a collection <col>
// Returns the element that occurs more than half of the time in the collection (the majority element)
// If there is no majority element, a random element is returned
template<typename C> requires std::ranges::range<C>
typename C::value_type Boyer_Moore_vote_algorithm(const C& col) {
	/*
		It works by maintaining a candidate and a counter:
		it increments the counter when the current element matches the candidate, decrements otherwise,
		and resets the candidate when the counter reaches zero.
		After one pass, the candidate is the majority element if one exists.
	*/
	typename C::value_type candidate;
	size_t frequence{ 0 };

	for (const auto& x : col) {
		if (frequence == 0) candidate = x;
		if (x == candidate) ++frequence;
		else --frequence;
	}
	return candidate;
	/*
		It does not guarantee that the candidate actually occurs more than half of the time.
		If there is no majority element, a random element is returned
	*/
}

// Given a collection <col>
// Returns the element that occurs more than half of the time in the collection (the majority element)
// If there is no majority element, returns std::nullopt
template<typename C> requires std::ranges::range<C>
std::optional<typename C::value_type> majority_element(const C& col) {
	std::unordered_map<typename C::value_type, size_t> mapping; // Mapping from collection elements to their frequency of occurrence
	size_t times = col.size() / 2; // Frequency of the most frequently occurring element

	for (const auto& x : col) {
		++mapping[x];
		if (mapping[x] > times) return x; // Found the majority element in collection
	}
	return std::nullopt; // If there is no majority element, returns std::nullopt
}

// Given an integer <number>
// Checks if the <number> is a palindrome
template<typename T> requires std::integral<T>
bool is_palindrome(const T& number) {
	if (number < 0) return false;
	return number == reversed(number);
}

// Given a string <line>
// Checks if the <line> is a palindrome
bool is_palindrome(const std::string& line);

// Given an integer <rows_count>
// Returns Pascal's triangle with <rows_count> rows
template<typename T = int>
std::vector<std::vector<T>> Pascal_triangle(size_t rows_count) {
	// Initialize the Pascal triangle
	std::vector<std::vector<T>> result(rows_count);

	for (size_t i{ 0 }; i < rows_count; ++i) {
		result[i] = std::vector<T>(i + 1, 1); // All elements are set to 1 by default to avoid having to specify additional conditions
		for (size_t j{ 1 }; j < i; ++j)
			result[i][j] = result[i - 1][j - 1] + result[i - 1][j]; // Element storage rule
	}
	return result;
}




#endif 
