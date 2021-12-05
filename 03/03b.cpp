#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <bitset>
#include <unordered_set>
#include <algorithm>
#include <functional>

unsigned int toDec(const std::string num) {
	unsigned int dec = 0;
	for (int i = 0; i < num.size(); ++i) {
		int n = num[i] > '0' ? 1 : 0;
		dec += n * std::pow(2, num.size() - 1 - i);
	}
	return dec;
}

std::string find(bool mostCommon, std::unordered_set<std::string> nums) {
	int index = 0;
	while (nums.size() > 1) {
		int out = 0;
		auto addSet = [&](const std::string& n) {
			out += n[index] == '0' ? -1 : 1; 
		};
		std::for_each(nums.begin(), nums.end(), addSet);
		auto it = nums.begin();
		while (it != nums.end()) {
			if ((mostCommon && ((out >= 0 && (*it)[index] == '0') || (out < 0 && (*it)[index] == '1')))
				|| (!mostCommon && ((out < 0 && (*it)[index] == '0') || (out >= 0 && (*it)[index] == '1')))) {
				it = nums.erase(it);
			}
			else {
				it++;
			}
		}
		index++;
	}
	std::cout << *nums.begin() << '\n';
	return *nums.begin();
}

int main() {
	std::ifstream input("input.txt");
	std::string in;
	std::unordered_set<std::string> bins;

	while (input >> in) {
		bins.insert(in);
	}
	unsigned int gammaRate = toDec(find(true, bins));
	unsigned int epsilonRate = toDec(find(false, bins));
	std::bitset<12> gammabits(gammaRate);
	std::bitset<12> epsilonBits(epsilonRate);
	std::cout << "Gamma: " << gammabits << '\n';
	std::cout << "Epsilon: " << epsilonBits << '\n';
	std::cout << gammaRate * epsilonRate << '\n';
}

