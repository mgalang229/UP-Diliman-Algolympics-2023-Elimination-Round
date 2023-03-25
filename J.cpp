#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> grid;
int n, m;

class Cell {
public:
	int row, col;
	char prev;
	string path;

	Cell() {}

	Cell(int r, int c, char pr, string p) : row(r), col(c), prev(pr), path(p) {}
};

bool is_num(char ch) {
	return '0' <= ch && ch <= '9';
}

int extract(char ch) {
	return ch - '0';
}

string find_path(vector<int>& num) {
	Cell src;
	// mark the black holes visited
	bool vis[n][m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == '#') {
				vis[i][j] = true;
			} else {
				vis[i][j] = false;
			}
			if (grid[i][j] == 'X') {
				src = Cell(i, j, '?', "");
			}
		}
	}
	int sz = num.size();
	int index = 0;
	queue<Cell> q;
	q.push(src);
	vis[src.row][src.col] = true;
	while (!q.empty()) {
		Cell p = q.front();
		q.pop();
		if (index < sz && extract(grid[p.row][p.col]) == num[index] && !vis[p.row][p.col]) {
			vis[p.row][p.col] = true;
			// clear the queue -> O(N) time complexity
			// while (!q.empty()) {
			// 	q.pop();
			// }
			// q = {};
			index++;
			if (index == sz) {
				return p.path;
			}
		}
		// don't visit the empty cell because it'll be used again

		// for lexicographic order: arrange these in alphabetical order
		
		// move right
		if (p.col + 1 < m && !vis[p.row][p.col+1] && p.prev != 'E') {	
			if (!is_num(grid[p.row][p.col+1]) || (index < sz && extract(grid[p.row][p.col+1]) == num[index])) {
				q.push(Cell(p.row, p.col + 1, 'E', p.path + "E"));
			}
		}

		// move up
		if (p.row - 1 >= 0 && !vis[p.row-1][p.col] && p.prev != 'N') {
			if (!is_num(grid[p.row-1][p.col]) || (index < sz && extract(grid[p.row-1][p.col]) == num[index])) {
				q.push(Cell(p.row - 1, p.col, 'N', p.path + "N"));
			}
		}

		// move down
		if (p.row + 1 < n && !vis[p.row+1][p.col] && p.prev != 'S') {
			if (!is_num(grid[p.row+1][p.col]) || (index < sz && extract(grid[p.row+1][p.col]) == num[index])) {
				q.push(Cell(p.row + 1, p.col, 'S', p.path + "S"));
			}
		}

		// move left
		if (p.col - 1 >= 0 && !vis[p.row][p.col-1] && p.prev != 'W') {
			if (!is_num(grid[p.row][p.col-1]) || (index < sz && extract(grid[p.row][p.col-1]) == num[index])) {
				q.push(Cell(p.row, p.col - 1, 'W', p.path + "W"));
			}
		}
	}
	return "IMPOSSIBLE";
}

void test_case(int& tc) {
	cin >> n >> m;
	grid = vector<vector<char>>(n, vector<char>(m));
	vector<int> num;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
			if (is_num(grid[i][j])) {
				num.push_back(extract(grid[i][j]));
			}
		}
	}
	// try finding the shortest path one-by-one: 9 -> 8 -> ... -> 0
	sort(num.rbegin(), num.rend());
	cout << find_path(num) << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T = 1;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		test_case(tc);
	}	
}
