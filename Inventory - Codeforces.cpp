// Link to the problem - http://codeforces.com/problemset/problem/569/B
#include <bits/stdc++.h>
using namespace std;

bool mp[100001] = {false};

void memset(bool mp[]) {
    for(int i = 0; i < 100001; ++i)
        mp[i] = false;
}

int main() {
    int n;
    cin >> n;
    int ar[n];
    vector<int> vec;

    for(int i = 0; i < n; ++i) {
        cin >> ar[i];
        mp[ar[i]] = true;
    }
    for(int i = 1; i <= n; ++i) {
        if(!mp[i])
            vec.push_back(i);
    }

    memset(mp);
    for(int i = 0, pos = 0; i < n and pos < vec.size(); ++i) {
        if(mp[ar[i]] or ar[i] > n) {
            ar[i] = vec[pos];
            ++pos;
        } else mp[ar[i]] = true;
    }

    for(auto i : ar)
        cout << i << " ";
}
