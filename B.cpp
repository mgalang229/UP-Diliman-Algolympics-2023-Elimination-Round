#include <bits/stdc++.h>
using namespace std;

void test_case(int& tc) {
	int d, w, b;
	cin >> d >> w >> b;
	int bnc = d / w;
	if (d % w == 0) {
		bnc--;
	}
	cout << (b >= bnc ? "YES" : "NO") << "\n";
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
