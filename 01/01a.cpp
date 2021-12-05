#include <iostream>
#include <fstream>

int main() {
	std::ifstream input("input.txt");
	int larger = 0;
	int in;
	int last = -1;
	while (input >> in) {
		if (last != -1 && in > last) {
			larger++;
		}
		last = in;
	}
	std::cout << larger << '\n';
}

