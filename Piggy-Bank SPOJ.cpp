#include <bits/stdc++.h>
using namespace std;

long long int dp[100000];
bool is_valid[100000];


void solve() {
    int piggy_weight, total_weight, num_coins, res_weight;
    cin >> piggy_weight >> total_weight >> num_coins;
    res_weight = total_weight - piggy_weight;
    pair<int, int> coins[num_coins];

    for(auto &i : coins)
        cin >> i.first >> i.second;
    fill(begin(dp), end(dp), LONG_LONG_MAX);
    fill(begin(is_valid), end(is_valid), false);
    dp[0] = 0;
    is_valid[0] = true;


    for(int w = 1; w <= res_weight; ++w) {
        for(int i = 0; i < num_coins; ++i) {
            if(coins[i].second <= w and is_valid[w - coins[i].second]) {
                is_valid[w] = true;
                dp[w] = min(dp[w], dp[w-coins[i].second] + coins[i].first);
            }
        }
    }

    cout << (is_valid[res_weight] ? "The minimum amount of money in the piggy-bank is " + to_string(dp[res_weight]) : "This is impossible") << ".\n";
}

int main() {
    int test;
    cin >> test;

    while(test--)
        solve();
}
