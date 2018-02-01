/* Codeforces Problem : Kefa and The Company (http://codeforces.com/problemset/problem/580/B)
 * 
 * Solution :-
 * 1. sort the money array
 * 2. Let i be the starting friend that will come to the party and j is the last friend that will come
 * if i comes. Then total friendship factor will be the sum fro i to j. We need to maximise this.
 * 3. Using brute force we can check for all such segments in O(N^2).
 * 4. Use binary search to find j for every i. 
 * 5. To find sum of friendship factor in the range i to j, either use a loop, this will take O(N) time,
 * making overall complexity O(N) * O(N*log(N))
 * 6. Alternatively, maintain a prefix-sum array to do the range query operation in O(1).
*/

#include <bits/stdc++.h>
using namespace std;

int binarySearch(int start, int end, int val, int diff, pair<int, int> ar[]) {
    while(start < end) {
        int mid = start + (end - start) / 2;
        if(ar[mid].first - val < diff)
            start = mid + 1;
        else
            end = mid;
    }

    if(ar[start].first - val >= diff)
        return start - 1;
    return start;
}

int main() {
    int n, d;
    cin >> n >> d;
    pair<int, int> ar[n];
    long long int prefix_sum[n], resl = LONG_LONG_MIN;

    for(int i = 0; i < n; ++i)
        cin >> ar[i].first >> ar[i].second;

    sort(ar, ar + n, [](pair<int, int> a, pair<int, int> b) {
        return a.first < b.first;
    });

    prefix_sum[0] = ar[0].second;
    for(int i = 1; i < n; ++i)
        prefix_sum[i] = prefix_sum[i-1] + ar[i].second;


    for(int i = 0; i < n; ++i) {
        int start = i, end;
        long long int temp;

        end = binarySearch(i, n - 1, ar[i].first, d, ar);
        temp = prefix_sum[end] - prefix_sum[start] + ar[start].second;

        if(temp > resl)
            resl = temp;
    }

    cout << resl;
}
