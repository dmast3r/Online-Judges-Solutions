Link to the problem - http://codeforces.com/problemset/problem/137/B

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, count = 0;
    cin >> n;
    vector<int> ar(n), extras;
    vector<bool> mp(5001, false);

    for(auto &i : ar) {
        cin >> i;
        mp[i] = true;
    }
    for(int i = 1; i <= 5000; ++i) {
        if (!mp[i])
            extras.push_back(i);
    }

    fill(mp.begin(), mp.end(), false);
    for(int i = 0, pos = 0; i < ar.size() and pos < extras.size(); ++i) {
        if(mp[ar[i]] or ar[i] > n) {
            ar[i] = extras[pos++];
            ++count;
        } else
            mp[ar[i]] = true;
    }

    //for(auto i : ar)
      //  cout << i << " ";
    cout << count;
}
