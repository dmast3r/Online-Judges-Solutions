#include <bits/stdc++.h>
using namespace std;

int binarySearch(int start, int dis, int pwr, pair<int, int> ar[]) {
    int end = 0;
    while(start > end) {
        int mid = end + (start - end) / 2;
        if(dis - ar[mid].first > pwr)
            end = mid + 1;
        else
            start = mid;
    }
    if(dis - ar[start].first > pwr)
        return start + 2;
    return start + 1;
}

int main() {
    int n, resl = INT_MAX;
    cin >> n;
    pair<int, int> ar[n];
    int prefix[n+1] = {0};

    for(auto &i : ar) {
        cin >> i.first;
        cin >> i.second;
    }
    sort(ar, ar + n , [](pair<int, int> a, pair<int, int> b){
        return a.first < b.first;
    });

    for(int i = 2; i <= n; ++i) {
        int pos = binarySearch(i - 2, ar[i-1].first, ar[i-1].second, ar);
        prefix[i] = i - pos + prefix[pos-1];
    }

    for(int i = n; i >= 0; --i)
        resl = min(resl, n - i + prefix[i]);
    cout << resl;
}
