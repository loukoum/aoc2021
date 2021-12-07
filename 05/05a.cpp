#include <iostream>
#include <fstream>
#include <memory>
#include <algorithm>
#include <vector>
#include <tuple>

class Map {
public:
	int width;
	int height;
	std::unique_ptr<int[]> values;

	Map() = delete;
	Map(int w, int h) : width(w), height(h) {
		values = std::make_unique<int[]>(w * h);
		for (int i = 0; i < w * h; ++i) {
			values[i] = 0;
		}
	}

	int index(int x, int y) {
		return x * height + y;
	}

	void add(const std::tuple<int, int, int, int>& line) {
		if (std::get<0>(line) != std::get<2>(line) && std::get<1>(line) != std::get<3>(line)) {
			return;
		}
		int startX = std::min(std::get<0>(line), std::get<2>(line));
		int endX = std::max(std::get<0>(line), std::get<2>(line));
		int startY = std::min(std::get<1>(line), std::get<3>(line));
		int endY = std::max(std::get<1>(line), std::get<3>(line));

		for (int x = startX; x <= endX; ++x) {
			for (int y = startY; y <= endY; ++y) {
				values[index(x, y)]++;
			}
		}
	}

	int getCrossed() const {
		int crossed = 0;
		for (int i = 0; i < width * height; ++i) {
			if (values[i] > 1) {
				crossed++;
			}
		}
		return crossed;
	}
};

int main() {
	std::ifstream input("input.txt");
	int width = 0;
	int height = 0;
	int x0, y0, x1, y1;
	std::vector<std::tuple<int, int, int, int>> values;

	while (input >> x0) {
		input.ignore();
		input >> y0;
		input.ignore();
		input.ignore();
		input.ignore();
		input.ignore();
		input >> x1;
		input.ignore();
		input >> y1;
		width = std::max(width, std::max(x0, x1));
		height = std::max(height, std::max(y0, y1));
		values.push_back(std::make_tuple(x0, y0, x1, y1));
	}
	width++;
	height++;
	std::cout << "Map: " << width << ' ' << height << '\n';
	Map map(width, height);
	for (const auto& fog : values) {
		map.add(fog);
	}
	std::cout << "Crossed: " << map.getCrossed() << '\n';
}

