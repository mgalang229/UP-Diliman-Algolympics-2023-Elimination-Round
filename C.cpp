#include <bits/stdc++.h>
using namespace std;

/*

11110001
11111110
11111111
= 2

100
111
= 1

00111001
11000110
11000110

*/

void test_case(int& tc) {
	int k;
	string s;
	cin >> k >> s;
	int cnt = 0;
	for (int i = 0; i < k; i++) {
		int index = i;
		while (index < k && s[index] == s[i]) {
			index++;
		}
		if (i == 0 && s[i] == '0') {
			cnt++;
		} else if (i > 0) {
			cnt++;
		}
		i = index - 1;
	}
	cout << cnt << "\n";
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
