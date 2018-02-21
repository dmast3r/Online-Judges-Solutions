//
// Created by sourabh on 20/2/18.
//

#include <bits/stdc++.h>
using namespace std;

bool pred(int v, int n, int k) {
    long long int sum = 0, m  = 1;
    while(v / m != 0) {
        sum += v / m;
        m *= k;
    }
    return sum >= n;
}

int binarySearch(int start, int end, int n, int k) {
    while(start < end) {
        int mid = start + (end - start) / 2;
        if(pred(mid, n, k))
            end = mid;
        else start = mid + 1;
    }
    return start;
}

int main() {
    int n, k;
    cin >> n >> k;

    cout << binarySearch(0, n, n, k) << endl;
}
