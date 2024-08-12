#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;
void dfs(int current, vector<vector<int>> &g, vector<bool> &flag) {
    flag[current - 1] = 1;

    for (int i: g[current - 1]) {
        if (flag[i - 1] != 1) {
            dfs(i, g, flag);
                    }
    }
}
 
void bfs() {
    int n;
    vector<vector<int>> g(n);
    vector<int> dist(n, -1);
    deque<int> q;
    q.push_back(0);
    while (!q.empty()) {
        int cur = q.front();
        q.pop_front();
        for (int i = 0; i < g[cur].size(); ++i) {
            if (dist[g[cur][i]] == -1) {
                dist[g[cur][i]] = dist[cur] + 1;
                q.push_back(g[cur][i]);
            }
        }
    }
}

void algorithm_deits() {
    int n;

    vector<vector<pair<int, int>>> g(n);
    vector<int> d(n, INT_MAX);

    d[0] = 0;

    set<pair<int, int>> q;
    q.insert({d[0], 0});

    while (!q.empty()) {
        int cur = q.begin()->second;
        q.erase(q.begin());

        for (auto [u, w]: g[cur]) {
            if (d[cur] + w < d[u]) {
                q.erase({d[u], u});
                d[u] = d[cur] + w;
                q.insert({d[u], u});
            }
        }
    }
}

int main() {

    return 0;
}