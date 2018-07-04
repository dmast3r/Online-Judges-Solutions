#include<bits/stdc++.h>
using namespace std;

bool is_prime[10001], is_visited[10001];

void calcPrimes() {
   fill(begin(is_prime), end(is_prime), true);
    is_prime[1] = is_prime[0] = false;

    for(int i = 2; i * i <= (int)1e4; ++i) {
        if(is_prime[i]) {
            for(int j = 2*i; j <= (int)1e4; j += i)
                is_prime[j] = false;
        }
    }
}

// place changed digit at pos in number
// 1 pos means 1's place
int getChangedNumber(int number, int pos, int digit) {
    string changed_num(4, '0');
    int p = 3;

    while (number != 0) {
        changed_num[p] = (char)(number % 10 + '0');
        number /= 10;
        --p;
    }
    changed_num[4-pos] = (char)('0'+digit);
    return stoi(changed_num);
}

void solve() {
    int low, high;
    cin >> low >> high;

    fill(begin(is_visited), end(is_visited), false);
    queue<pair<int, int>> q; // the number : level
    q.push(make_pair(low, 0));

    while (!q.empty()) {
        int number = q.front().first, level = q.front().second;
        q.pop();

        if(number == high) {
            cout << level << endl;
            return;
        }

        for(int p = 1; p <= 4; ++p) {
            for(int d = 0; d <= 9; ++d) {
                if(p == 4 and d == 0)
                    continue;

                int changed_number = getChangedNumber(number, p, d);
                //cout << "changed_number = " << changed_number << endl;
                if(!is_visited[changed_number] and is_prime[changed_number]) {
                    is_visited[changed_number] = true;
                    q.push(make_pair(changed_number, level+1));
                }
            }
        }
    }

    cout << endl;

}

int main() {
    int test;
    cin >> test;

    calcPrimes();

    while(test--)
        solve();
    return 0;
}
