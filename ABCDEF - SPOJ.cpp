#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, sum = 0;
    cin >> n;
    vector<long long int> a(n), b(n), c(n), d, e(n), f(n), v1, v2;

    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        f[i] = e[i] = c[i] = b[i] = a[i];
        if(a[i] != 0)
            d.push_back(a[i]);
    }

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            for(int k = 0; k < n; ++k)
                v1.push_back(a[i] * b[j] + c[k]);
        }
    }

    for(int i = 0; i < d.size(); ++i) {
        for(int j = 0; j < n; ++j) {
            for(int k = 0; k < n; ++k)
                v2.push_back(d[i] * (e[j] + f[k]));
        }
    }

    sort(v2.begin(), v2.end());

    for(auto i : v1) {
        auto pr = equal_range(v2.begin(), v2.end(), i);
        sum += pr.second - pr.first;
    }
    cout << sum;
}

int main() {
    solve();
    return 0;
}
