// Michael Kukulka
// CIS 1202 N01
// December 06, 2024

#include "commonutils.hpp"
#include <iomanip>

class InvalidCharacterException : public std::exception {
public: 
	InvalidCharacterException(void) = default;
};

class InvalidRangeException : public std::exception {
public:
	InvalidRangeException(void) = default;
};

char character(char start, int offset);

int main() {
	std::vector<std::pair<char, int>> testValues = { {'a', 1}, {'a', -1}, {'Z', -1}, {'?', 5}, {'a', 32}, {'z', -26}, {'a', 26}};
	char result;
	for (std::pair<char, int> test : testValues) {
		std::cout << "Char is: " << test.first << " | Int is: " << std::setw(3) << test.second << " | ";
		try {
			result = character(test.first, test.second);
			std::cout << "Result is: " << result << "\n";
		}
		catch (InvalidCharacterException) {
			std::cout << "Encountered invalid character exception\n";
			continue;
		}
		catch (InvalidRangeException) {
			std::cout << "Encountered invalid range exception\n";
			continue;
		}
	}
	return EXIT_SUCCESS;
}

char character(char start, int offset) {
	int result = start + offset;
	if (!isalpha(start)) {
		throw InvalidCharacterException();
	}
	if (!isalpha(result) || islower(result) != islower(start)) {
		throw InvalidRangeException();
	}
	return result;
}