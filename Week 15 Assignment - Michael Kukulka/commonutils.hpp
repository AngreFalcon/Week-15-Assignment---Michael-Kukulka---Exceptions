#pragma once

#include <iostream>
#include <limits>
#include <random>
#include <string>

template<typename T>
T getNum(const std::string& prompt, T min = std::numeric_limits<T>::min(), T max = std::numeric_limits<T>::max()) {
	T num = 0;
	std::cout << prompt;
	while (!(std::cin >> num) || std::cin.fail() || num < min || num > max) {
		std::cin.clear();
		std::cin.ignore((std::numeric_limits<std::streamsize>::max() - 1), '\n');
		std::cin.sync();
		std::cout << "Invalid selection. Please enter a number " << static_cast<size_t>(min) << "-" << static_cast<size_t>(max) << ": ";
	}
	std::cin.ignore((std::numeric_limits<std::streamsize>::max() - 1), '\n');
	return num;
}

inline int64_t getRandom(int64_t min = std::numeric_limits<int64_t>::min(), int64_t max = std::numeric_limits<int64_t>::max()) {
	static std::random_device rand_dev;
	std::mt19937 generator(rand_dev());
	std::uniform_int_distribution<int64_t> distr(min, max);
	return distr(generator);
}

template<typename T>
void swapValues(T &a, T &b) {
	T temp = 0;
	temp = a;
	a = b;
	b = temp;
	return;
}