#include <bits/stdc++.h>
using namespace std;
long long int ar[10000];
void solve() {
	int size;
	long long int sum = 0;
	cin >> size;
	for(int i = 0; i< size; ++i) {
		cin >> ar[i];
		sum += (2 * i + 1 - size) * ar[i];
	}
	cout << sum << endl;
}

int main() {
	int test;
	cin >> test;
	while(test--)
		solve();
}
