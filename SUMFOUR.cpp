#include <bits/stdc++.h>
using namespace std;

void createSumPair(int x[], int y[], vector<int> &sumar, int size) {
	for(int i = 0; i < size; ++i)
		for(int j = 0; j < size; ++j)
			sumar.push_back(x[i] + y[j]);
}

void solve() {
	int n, cnt = 0;
	scanf("%d", &n);
	int a[n], b[n], c[n], d[n];
	vector<int> sab, scd;

	for(int i = 0; i < n; ++i)
		scanf("%d%d%d%d", &a[i], &b[i], &c[i], &d[i]);

	createSumPair(a, b, sab, n);
	createSumPair(c, d, scd, n);

 	sort(scd.begin(), scd.end());

 	for(auto i : sab) {
 		auto resl = equal_range(scd.begin(), scd.end(), -i);
 		cnt += resl.second - resl.first;
 	}

 	printf("%d\n", cnt);
}

int main() {
	solve();
}