#include <iostream>
#include <fstream>
#include <utility>

void move(const std::string& dir, int dist, std::pair<int, int>& out) {
	if (dir == "forward") {
		out.first += dist;
	}
	else if (dir == "up") {
		out.second -= dist;
	}
	else if (dir == "down") {
		out.second += dist;
	}
}

int main() {
	std::ifstream input("input.txt");
	std::pair<int, int> pos(0, 0);
	std::string dir;
	int dist;

	while (input >> dir) {
		input >> dist;
		move(dir, dist, pos);
	}
	std::cout << pos.first * pos.second << '\n';
}

