//
// Created by sourabh on 22/2/18.
//

#include <bits/stdc++.h>
using namespace std;

long long int getCombinations(long long int choice) {
    return (choice > 1 ? choice * (choice - 1) / 2 : 0);
}

int main() {
    long long int n, d;
    long long int ans = 0;
    cin >> n >> d;
    long long int ar[n];

    for(auto &i : ar)
        cin >> i;

    for(long long int i = 0; i < n; ++i) {
        long long int choice = (upper_bound(ar, ar + n, ar[i] + d) - ar - 1) - i;
        ans += getCombinations(choice);
    }

    cout << ans;
}
