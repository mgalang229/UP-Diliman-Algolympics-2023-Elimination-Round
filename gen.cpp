#include <bits/stdc++.h>
using namespace std;

int main() {
	srand(time(0));
	for (int i = 0; i < 13; i++) {
		cout << rand() % 9 + 1 << " ";
	}
	cout << "\n";
}
