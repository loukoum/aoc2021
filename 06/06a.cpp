#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>

void update(std::vector<unsigned long long>& fish) {
	unsigned long long newFish = fish[0];
	for (int i = 0; i < fish.size() - 1; ++i) {
		fish[i] = fish[i + 1];
	}
	fish[8] = newFish;
	fish[6] += newFish;
}

int main() {
	std::ifstream input("input.txt");
	std::vector<unsigned long long> fish;
	unsigned long long n;

	fish.resize(9);
	for (int i = 0; i < fish.size(); ++i) {
		fish[i] = 0;
	}

	while (input >> n) {
		input.ignore();
		fish[n]++;
	}

	for (int i = 0; i < 256; ++i) {
		update(fish);
	}
	unsigned long long numFish = std::accumulate(fish.begin(), fish.end(), 0L);
	std::cout << "Fish: " << numFish << '\n';
}

