#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>

int main() {
	std::ifstream input("input.txt");
	int larger = 0;
	int in;
	std::vector<int> lastValues = { -1, -1, -1 };
	int last = -1;
	int index = 0;
	while (input >> in) {
		int idx = index % 3;
		lastValues[idx] = in;
		if (index >= 2) {
			int accum = std::accumulate(lastValues.begin(), lastValues.end(), 0);
			if (last != -1 && accum > last) {
				larger++;
			}
			last = accum;
		}
		index++;
	}
	std::cout << larger << '\n';
}

