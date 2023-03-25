#include <bits/stdc++.h>
using namespace std;

void test_case(int& tc) {
	int n, r, q;
	cin >> n >> r >> q;
	map<string, int> num_node;
	long long cost[n];
	for (int i = 0; i < n; i++) {
		string color;
		long long ct;
		cin >> color >> ct;
		num_node[color] = i;
		cost[i] = ct;
	}
	vector<int> adj[n];
	map<pair<int, int>, long long> weight;
	for (int i = 0; i < r; i++) {
		string u, v;
		long long w;
		cin >> u >> v >> w;
		adj[num_node[v]].push_back(num_node[u]);
		weight[make_pair(num_node[v], num_node[u])] = w;
	}
	string stars[q];
	for (int i = 0; i < q; i++) {
		cin >> stars[i];
	}
	int in[n];
	memset(in, 0, sizeof(in));
	for (int u = 0; u < n; u++) {
		for (int v : adj[u]) {
			in[v]++;
		}
	}
	multiset<int> ms;
	for (int u = 0; u < n; u++) {
		if (in[u] == 0) {
			ms.insert(u);
		}
	}
	assert((int) ms.size() > 0);
	long long extra[n];
	memset(extra, 0, sizeof(extra));
	int cnt = 0;
	while (!ms.empty()) {
		int u = *ms.begin();
		ms.erase(ms.find(*ms.begin()));
		if (extra[u] > 0) {
			cost[u] = min(cost[u], extra[u]);
		}
		for (int& v : adj[u]) {
			extra[v] += cost[u] * weight[make_pair(u, v)];
			if (--in[v] == 0) {
				ms.insert(v);
			}
		}
		cnt++;
	}
	assert(cnt == n);
	for (int i = 0; i < q; i++) {
		cout << cost[num_node[stars[i]]] << " ";
	}
	cout << "\n";
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
