#include<bits/stdc++.h>
using namespace std;

// https://en.wikipedia.org/wiki/Directed_acyclic_graph
// https://en.wikipedia.org/wiki/Topological_sorting
// https://www.geeksforgeeks.org/topological-sorting/
// https://www.geeksforgeeks.org/topological-sorting-indegree-based-solution/?ref=rp
// https://www.geeksforgeeks.org/lexicographically-smallest-topological-ordering/?ref=rp

vector<vector<int>> adj;

void add_edge(int u,int v) {
	adj[u].push_back(v);
}

vector<int> top_sort() {
	int n = adj.size();
	vector<int> in(n, 0);
	for (int u = 0; u < n; u++) {
		for (int& v : adj[u]) {
			in[v]++;
		}
	}
	multiset<int, greater<int>> ms;
	for (int i = 0; i < n; i++) {
		if (in[i] == 0) {
			ms.insert(i);
		}
	}
	int cnt = 0;
	vector<int> vec;
	while (!ms.empty()) {
		int u = *ms.begin();
		ms.erase(ms.begin());
		vec.push_back(u);
		for (int& v : adj[u]) {
			if (--in[v] == 0) {
				ms.insert(v);
			}
		}
		cnt++;
	}
	if (cnt != n) {
		return {-1};
	}
	return vec;
}

void test_case(int& tc) {
	int n, m;
	cin >> n >> m;
	adj= vector<vector<int>>(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		add_edge(u, v);
	}
	vector<int> res = top_sort();
	if (res[0] == -1) {
		cout << "IMPOSSIBLE\n";
		return;
	}
	for (int& x : res) {
		cout << x + 1 << " ";
	}
	cout << "\n";
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
