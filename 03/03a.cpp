#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <bitset>

void add(const std::string& in, std::vector<int>& out) {
	if (in.size() > out.size()) {
		out.resize(in.size());
	}
	for (int i = 0; i < in.size(); ++i) {
		out[i] += in[i] == '0' ? -1 : 1;
	}
}

unsigned int toDec(const std::vector<int>& num) {
	unsigned int dec = 0;
	for (int i = 0; i < num.size(); ++i) {
		int n = num[i] > 0 ? 1 : 0;
		dec += n * std::pow(2, num.size() - 1 - i);
	}
	return dec;
}

int main() {
	std::ifstream input("input.txt");
	std::string in;
	std::vector<int> out;

	while (input >> in) {
		add(in, out);
	}
	unsigned int gammaRate = toDec(out);
	unsigned int epsilonRate = gammaRate ^ 0b111111111111;
	std::bitset<12> gammabits(gammaRate);
	std::bitset<12> epsilonBits(epsilonRate);
	std::cout << "Gamma: " << gammabits << '\n';
	std::cout << "Epsilon: " << epsilonBits << '\n';
	std::cout << gammaRate * epsilonRate << '\n';
}

