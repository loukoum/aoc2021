#include <iostream>
#include <fstream>
#include <tuple>

void move(const std::string& dir, int dist, std::tuple<int, int, int>& out) {
	if (dir == "forward") {
		std::get<0>(out) += dist;
		std::get<1>(out) += std::get<2>(out) * dist;
	}
	else if (dir == "up") {
		std::get<2>(out) -= dist;
	}
	else if (dir == "down") {
		std::get<2>(out) += dist;
	}
}

int main() {
	std::ifstream input("input.txt");
	std::tuple<int, int, int> pos = std::make_tuple(0, 0, 0);
	std::string dir;
	int dist;

	while (input >> dir) {
		input >> dist;
		move(dir, dist, pos);
	}
	std::cout << std::get<0>(pos) * std::get<1>(pos) << '\n';
}

