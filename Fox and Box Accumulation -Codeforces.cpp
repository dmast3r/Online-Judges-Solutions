// Link to the problem - http://codeforces.com/problemset/problem/388/A
// O(N ^ 2) approach

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> ar(n), aux;

    for(auto &i : ar)
        cin >> i;
    sort(ar.begin(), ar.end());

    for(int i = 0; i < ar.size(); ++i) {
        bool inserted = false;
        for(int j = 0; j < aux.size(); ++j) {
            if(aux[j] <= ar[i]) {
                ++aux[j];
                inserted = true;
                break;
            }
        }
        if(!inserted)
            aux.push_back(1);
    }
    cout << aux.size();
}
