#include<bits/stdc++.h>
using namespace std;

bool isValid(int i, int j, int m, int n) {
    return i >= 0 and i < m and j >= 0 and j < n;
}

void multiBFSUtil(const vector<vector<int>> &graph, vector<vector<int>> &dist, set<pair<int, pair<int, int>>> &st) {
    int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
    auto m = (int)graph.size(), n = (int)graph[0].size();

    while (!st.empty()) {
        pair<int, pair<int, int>> top = *st.begin();
        int i = top.second.first, j = top.second.second;
        st.erase(st.begin());

        for(int k = 0; k < 4; ++k) {
            if(isValid(i+dx[k], j+dy[k], m, n) and dist[i+dx[k]][j+dy[k]] > dist[i][j] + 1) {
                auto it = st.find({dist[i+dx[k]][j+dy[k]], {i+dx[k], j+dy[k]}});
                st.erase(it);
                dist[i+dx[k]][j+dy[k]] = dist[i][j]+1;
                st.insert({dist[i][j] + 1, {i+dx[k], j+dy[k]}});
            }
        }
    }
}

void multiBFS(const vector<vector<int>> &graph) {
    int m, n;
    vector<vector<int>> dist(m = graph.size(), vector<int>(n = graph[0].size(), 100000));
    set<pair<int, pair<int, int>>> st; // distance from source : i,j

    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            if(graph[i][j] == 1)
                dist[i][j] = 0;
            st.insert({dist[i][j], {i, j}});
        }
    }

    multiBFSUtil(graph, dist, st);

    for(auto i : dist) {
        for(auto j : i)
            cout << j << " ";
        cout << endl;
    }
}

void solve() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> graph(m, vector<int>(n, 0));

    for(int i = 0; i < m; ++i) {
        string str;
        cin >> str;

        for(int j = 0; j < n; ++j)
            graph[i][j] = (int)(str[j]-'0');
    }

    multiBFS(graph);
}

int main() {
    int test;
    cin >> test;

    while (test--)
        solve();
}
