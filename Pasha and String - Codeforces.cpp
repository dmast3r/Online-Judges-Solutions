// Link to the problem - http://codeforces.com/problemset/problem/525/B

#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    unsigned long long m, half_size, sum = 0;
    cin >> str >> m;
    half_size = str.length() / 2;
    int sum_ar[half_size] = {0};

    for(int i = 0; i < m; ++i) {
        int index;
        cin >> index;
        --index;

        ++sum_ar[index];
    }

    for(int  i = 0; i < half_size; ++i) {
        sum += sum_ar[i];
        if(sum & 1)
            swap(str[i], str[str.length() - i - 1]);
    }

    cout << str;
}
