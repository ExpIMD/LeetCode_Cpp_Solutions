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