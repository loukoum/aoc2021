#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <utility>

class Board {
public:
	bool found[5][5];
	std::unordered_map<int, std::pair<int, int>> nums;

	Board() {
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				found[i][j] = false;
			}
		}
	}

	void add(int x, int y, int n) {
		nums[n] = std::make_pair(x, y);
	}

	void check(int n) {
		if (nums.find(n) != nums.end()) {
			std::pair<int, int>& pos = nums[n];
			found[pos.first][pos.second] = true;
		}
	}

	int getScore() const {
		int score = 0;
		for (const auto& p : nums) {
			if (!found[p.second.first][p.second.second]) {
				score += p.first;
			}
		}
		return score;
	}

	bool isComplete() const {
		for (int i = 0; i < 5; ++i) {
			bool row = true;
			bool col = true;
			for (int j = 0; j < 5; ++j) {
				row = row && found[i][j];
				col = col && found[j][i];
				if (!row && !col) {
					break;
				}
			}
			if (row || col) {
				return true;
			}
		}
		return false;
	}
};

void readNumbers(std::ifstream& input, std::vector<int>& nums) {
	int n;
	while (input >> n) {
		nums.push_back(n);
		if ((char)input.peek() != ',') {
			break;
		}
		input.ignore();
	}
}

Board parseBoard(std::ifstream& input) {
	Board b;
	int n;
	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 5; ++x) {
			input >> n;
			b.add(x, y, n);
		}
	}
	return b;
}

void readBoards(std::ifstream& input, std::vector<Board>& boards) {
	while (input) {
		boards.push_back(parseBoard(input));
	}
	boards.erase(boards.begin() + boards.size() - 1);
}

int main() {
	std::ifstream input("input.txt");
	std::vector<int> nums;
	std::vector<Board> boards;
	readNumbers(input, nums);
	readBoards(input, boards);

	std::cout << "Found: " << boards.size() << " boards" << '\n';
	for (const auto& n : nums) {
		auto it = boards.begin();
		while (it != boards.end()) {
			it->check(n);
			if (it->isComplete()) {
				if (boards.size() == 1) {
					std::cout << "Score: " << it->getScore() * n << '\n';
					return 0;
				}
				it = boards.erase(it);
			}
			else {
				it++;
			}
		}
	}
	std::cout << "This should not run... There is an error!" << '\n';
}

