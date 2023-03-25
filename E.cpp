#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/number-of-trailing-zeroes-in-base-b-representation-of-n/
// https://www.geeksforgeeks.org/legendres-formula-highest-power-of-prime-number-that-divides-n/
// https://www.geeksforgeeks.org/largest-power-k-n-factorial-k-may-not-prime/
// https://www.geeksforgeeks.org/prime-factor/

long long get_pow(long long n, long long p) {
	// trying a different implementation
	long long x = 0;
	while (n > 0) {
		n /= p;
		x += n;
	}
	return x;
}

vector<pair<long long, long long>> get_prime_fact(long long x) {
	vector<pair<long long, long long>> primes;
	long long cnt = 0;
	while (x % 2 == 0) {
		x /= 2;
		cnt++;
	}
	if (cnt > 0) { // don't forget the basic condition
		primes.push_back(make_pair(2, cnt));
	}
	for (long long i = 3; i * i <= x; i += 2) {
		if (x % i != 0) {
			continue;
		}
		cnt = 0;
		while (x % i == 0) {
			x /= i;
			cnt++;
		}
		if (cnt > 0) { // don't forget the basic condition
			primes.push_back(make_pair(i, cnt));
		}
	}
	if (x > 2) {
		primes.push_back(make_pair(x, 1));
	}
	return primes;
}

long long get_trail_zeroes(long long n, long long m) {
	vector<pair<long long, long long>> res = get_prime_fact(m);
	long long ans = LLONG_MAX;
	for (int i = 0; i < (int) res.size(); i++) {
		ans = min(ans, get_pow(n, res[i].first) / res[i].second);
	}
	return ans;
}

void test_case(int& tc) {
	long long n, m;
	cin >> n >> m;
	long long ans = get_trail_zeroes(n, m);
	if (ans == LLONG_MAX) { // don't forget the basic condition
		ans = 0;
	}
	cout << ans << "\n";
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
