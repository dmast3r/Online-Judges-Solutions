#include <bits/stdc++.h>
using namespace std;

const int MOD = (int)1e8;

int binarySearch(int start, int end, int val, pair<int, int> ar[]) {
    while (start < end) {
        int mid = start + (end-start+1) / 2;
        if(ar[mid].second > val)
            end = mid - 1;
        else
            start = mid;
    }
    return (ar[start].second <= val ? start : -1);
}

void solve(int n) {
    pair<int, int> ar[n];
    long long dp[n], sum[n];

    for(int i = 0; i < n; ++i) {
        cin >> ar[i].first >> ar[i].second;
        dp[i] = 1;
    }
    sort(ar, ar + n, [](pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    });

    sum[0] = 1;
    for(int i = 1; i < n; ++i) {
        int index = binarySearch(0, i-1, ar[i].first, ar);
        if(index != -1) {
            dp[i] =  (dp[i] % MOD + sum[index] % MOD) % MOD;
        }
        sum[i] = (sum[i-1] % MOD + dp[i] % MOD) % MOD;
    }

    int digits = (int)log10(sum[n-1]) + 1;
    for(int i = 0; i < 8 - digits; ++i)
       cout << 0;
    cout << sum[n-1] << endl;
}

int main() {
    int n;
    while(true) {
        cin >> n;
        if(n == -1)
            break;
        solve(n);
    }
}
