#include "leetcode_solutions.h"


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

// Given a string <line>
// Checks if the <line> is a palindrome
bool is_palindrome(const std::string& line) {
	if (line.empty()) return true; // We will consider the empty string as a palindrome

	size_t left{ 0 }, right{ line.size() - 1 }; // Initialize two pointers: one at the start and one at the end of the string

	while (left < right) {
		if (!std::isalnum(line[left])) { // If the character at 'left' is not alphanumeric, skip it
			++left;
			continue;
		}
		if (!std::isalnum(line[right])) { // If the character at 'right' is not alphanumeric, skip it
			--right;
			continue;
		}
		if (line[left] != line[right]) return false; // Characters do not match, not a palindrome
		else { // Characters match; move inward towards the center
			++left;
			--right;
		}
	}

	return true;
}

