#include <bits/stdc++.h>
using namespace std;

int main() {
    int rounds, max_score = INT_MIN;
    cin >> rounds;
    map<string, int> mp;
    vector<pair<string, int>> inputs(rounds);
    vector<string> winners;

    for(int i = 0; i < rounds; ++i) {
        int score;
        string str;
        cin >> str >> score;
        mp[str] += score;
        inputs[i] = make_pair(str, score);
    }

    for(auto &i : mp) {
        //cout << i.first << " " << i.second << endl;
        if(i.second > max_score) {
            max_score = i.second;
            winners.clear();
            winners.push_back(i.first);
        }
        else if(i.second == max_score)
            winners.push_back(i.first);
        i.second = 0;
    }

    for(auto i : inputs) {
        mp[i.first] += i.second;
        if(mp[i.first] >= max_score and find(winners.begin(), winners.end(), i.first) != winners.end()) {
            cout << i.first;
            break;
        }
    }
}
