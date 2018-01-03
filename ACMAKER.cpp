#include <bits/stdc++.h>
using namespace std;

long long int totalSubstr(string t, string p, int st, int sp, map<pair<int, int>, long long int> mp) {
    int tl = t.length(), pl = p.length(), resl = 0;
    pair<int, int> pr = make_pair(st, sp);

    // check for memoization
    if(mp.count(pr) > 0)
        return mp[pr];

    // base case
    if(sp == pl - 1) {
        int total = 0;
        for(int i = st; i < tl; ++i) {
            if(t[i] == p[sp])
                ++total;
        }
        return mp[pr] = total;
    }

    for(int i = st; tl - i >= pl - sp;) {
        int pos = t.find(p[sp], i);
        if(pos == string :: npos)
            break;
        resl += totalSubstr(t, p, pos + 1, sp + 1, mp);
        i = pos + 1;
    }

    return mp[pr] = resl;
}

long long int totalWays(const string &acro, const vector<string> &words, int acno, int wno, map<pair<int, int>, long long int> mp) {
    pair<int, int> pr = make_pair(acno, wno);

    if(mp.count(pr) != 0)
        return mp[pr];

    if(wno == words.size() - 1)
        return mp[pr] = totalSubstr(words[wno], acro.substr(acno, acro.length() - acno), 0, 0,
        *new map<pair<int, int>, long long int>);

    int resl = 0;
    for(int i = acno; acro.length() - i >= words.size() - wno; ++i) {
        int total = totalSubstr(words[wno], acro.substr(acno, i - acno + 1), 0, 0, *new map<pair<int, int>, long long int>);
        if(total == 0)
            break;
        resl += total * totalWays(acro, words, i + 1, wno + 1, mp);
    }
    return mp[pr] = resl;
}

vector<string> split(const string &text, const string &delim) {
    vector<string> *tokens = new vector<string>();
    int l = 0, r;

    while((r = text.find(delim, l)) != string :: npos) {
        string token = text.substr(l, r - l);
        if(token.length() > 0)
            tokens -> push_back(token);

        l = r + delim.length();
    }
    tokens -> push_back(text.substr(l, text.length() - l));

    return *tokens;
}

void solve(int num_insigf) {
    vector<string> insigf;
    string str;

    for(int i = 0; i < num_insigf; ++i) {
        cin >> str;
        insigf.push_back(str);
    }

    cin.ignore();
    while(getline(cin, str)) {
        long long int resl;
        map<pair<int, int>, long long int> mp;
        vector<string> temp = split(str, " "), words;
        string acro = temp[0], acro_lower = "";

        if(acro == "LAST" and temp.size() ==  2 and temp[1] == "CASE")
            break;

        for(int i = 1; i < temp.size(); ++i) {
            if(find(insigf.begin(), insigf.end(), temp[i]) == insigf.end())
            words.push_back(temp[i]);
        }

        for(auto i : acro)
            acro_lower += tolower(i);

        resl = totalWays(acro_lower, words, 0, 0, mp);
        if(resl == 0)
            cout << acro << " is not a valid abbreviation";
        else
            cout << acro << " can be formed in " << resl << " ways";
        cout << endl;
    }
}

int main() {
    int num_insigf;
    while(cin >> num_insigf and num_insigf != 0)
        solve(num_insigf);
}





