// Link to the problem - http://codeforces.com/problemset/problem/812/C
#include <bits/stdc++.h>
using namespace std;

long long int findCost(int n, int items, int ar[]) {
    long long int sum = 0;
    long long int cost_ar[n];

    for(int i = 0; i < n; ++i)
        cost_ar[i] = ar[i] + (i+1) * (long long int)items;
    sort(cost_ar, cost_ar + n);

    for(int i = 0; i < items; ++i)
        sum += cost_ar[i];
    return sum;
}

bool pred(int n, int k, int budget, int ar[]) {
    return budget >= findCost(n, k, ar);
}

int broughtMax(int n, int budget, int ar[]) {
    int start = 1, end = n;
    while (start < end) {
        int mid = start + (end - start) / 2 + 1;
        if(pred(n, mid, budget, ar))
            start = mid;
        else
            end = mid - 1;
    }
    return (pred(n, start, budget, ar) ? start : 0);
}

int main() {
    int n, s, max_brought, min_cost = 0;
    cin >> n >> s;
    int ar[n];

    for(auto &i : ar)
        cin >> i;

    max_brought = broughtMax(n, s, ar);
    min_cost = findCost(n, max_brought, ar);

    cout << max_brought << " " << min_cost;
}
