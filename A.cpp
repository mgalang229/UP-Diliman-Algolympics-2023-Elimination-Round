#include <bits/stdc++.h>
using namespace std;

void test_case(int& tc) {
	int d, n;
	cin >> d >> n;
	int a[d], b[d];
	for (int i = 0; i < d; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < d; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < n; i++) {
		bool ok = true;
		for (int j = 0; j < d; j++) {
			int t;
			cin >> t;
			ok &= (t >= a[j] - b[j] && t <= a[j]);
		}
		cout << (ok ? "SUS" : "INNOCENT") << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T = 1;
	// cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		test_case(tc);
	}
}
