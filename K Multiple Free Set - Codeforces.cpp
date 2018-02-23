//
// Created by sourabh on 22/2/18.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    if(k == 1) {
        cout << n;
        return 0;
    }

    long long int ar[n];
    bool mark[n];

    for(int i = 0; i < n; ++i) {
        cin >> ar[i];
        mark[i] = true;
    }
    sort(ar, ar + n);

    for(int i = 0; i < n; ++i) {
        if(mark[i]) {
            int upper_index = upper_bound(ar, ar + n, ar[i] * k) - ar,
                    lower_index = lower_bound(ar, ar + n, ar[i] * k) - ar;
            for(int j = lower_index; j != upper_index; ++j)
                mark[j] = false;
        }
    }

    cout << accumulate(mark, mark + n, 0);
}
