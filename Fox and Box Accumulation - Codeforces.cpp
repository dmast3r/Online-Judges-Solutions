// Link to the problem - http://codeforces.com/problemset/problem/388/A

#include <bits/stdc++.h>
using namespace std;

int binarySearch(int start, int end, const int &val, const vector<int> &ar) {
    if(ar.size() == 0)
        return -1;

    while(start < end) {
        int mid = start + (end - start) / 2;
        if(ar[mid] <= val)
            end = mid;
        else
            start = mid + 1;
    }
    return (ar[start] <= val ? start : -1);
}

int main() {
    int n;
    cin >> n;
    vector<int> ar(n), aux;

    for(auto &i : ar)
        cin >> i;
    sort(ar.begin(), ar.end());

    for(int i = 0; i < ar.size(); ++i) {
        int index = binarySearch(0, aux.size() - 1, ar[i], aux);
        if(index != -1)
            ++aux[index];
        else
            aux.push_back(1);
    }
    cout << aux.size();
}
