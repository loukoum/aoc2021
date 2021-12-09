#include <iostream>
#include <fstream>
#include <vector>

long long sum(long long n) {
	return (n * (n + 1)) / 2;
}

int main() {
	std::ifstream input("input.txt");
	std::vector<unsigned long long> crabs;
	long long maxFuel = 0;
	long long n;

	while (input >> n) {
		input.ignore();
		maxFuel = std::max(maxFuel, n);
		crabs.push_back(n);
	}

	long long fuelNeeded = sum(maxFuel * crabs.size());
	for (long long i = 0L; i < maxFuel; ++i) {
		long long curFuel = 0L;
		for (const auto& c : crabs) {
			curFuel += sum(std::abs((long long)(i - c)));
		}
		if (curFuel < fuelNeeded) {
			fuelNeeded = curFuel;
		}
	}
	std::cout << "Fuel needed: " << fuelNeeded << '\n';
}

