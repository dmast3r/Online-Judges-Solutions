// http://codeforces.com/contest/607/problem/A
// Created by sourabh on 17/2/18.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, covered = 0, start = 0;
    cin >> n >> m;
    int a[n], b[m];

    for(auto &i : a)
        cin >> i;
    for(auto &i : b)
        cin >> i;
    for(int i = 0; i < n; ++i) {
        int pos = lower_bound(b + start, b + m, a[i]) - b;
        if(pos == m) {
            cout << n - i;
            return 0;
        }
        start = pos + 1;
    }
    cout << 0;
}
