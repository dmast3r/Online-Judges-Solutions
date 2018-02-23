//
// Created by sourabh on 22/2/18.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ar[n];

    for(auto &i : ar)
        cin >> i;
    sort(ar, ar + n);

   int start = n / 2, count = n;
   for(int i = 0; i < n/2; ++i) {
       int here = lower_bound(ar + start, ar + n, ar[i] * 2) - ar;
       if(here == n)
           break;
       --count;
       start = here + 1;
   }

   cout << count;
}
