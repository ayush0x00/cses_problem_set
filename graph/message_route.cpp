#include <bits/stdc++.h>
using namespace std;

int min_len = INT_MAX;
vector<int> path;

void bfs(int dest, const vector<vector<int>> &graph, vector<bool> &vis)
{
    queue<int> q;
    q.push(1);
    vector<int> parent(graph.size());
    while (!q.empty())
    {
        int src = q.front();
        if (src == dest)
            break;
        q.pop();
        for (auto nbr : graph[src])
        {
            if (!vis[nbr])
            {
                vis[nbr] = true;
                parent[nbr] = src;
                q.push(nbr);
            }
        }
    }
    if (!vis[dest])
        cout << "IMPOSSIBLE\n";
    else
    {
        vector<int> path;
        path.push_back(dest);
        int start = dest;
        while (start != 1)
        {
            start = parent[start];
            path.push_back(start);
        }
        reverse(path.begin(), path.end());
        cout << path.size() << "\n";
        for (auto i : path)
            cout << i << " ";
    }
    return;
}

void dfs(int src, int dest, vector<int> &psof, vector<bool> &vis, const vector<vector<int>> &graph)
{
    // will give TLE
    if (src == dest)
    {
        if (psof.size() < min_len)
        {
            path = psof;
            min_len = path.size();
        }
        return;
    }
    vis[src] = true;
    for (auto nbr : graph[src])
    {
        if (!vis[nbr])
        {
            psof.push_back(nbr);
            dfs(nbr, dest, psof, vis, graph);
            psof.pop_back();
        }
    }
    vis[src] = false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#ifndef ONLINE_JUDGE
    freopen("test_input.txt", "r", stdin);
#endif

    int m, n;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    vector<bool> vis(n + 1);
    for (int i = 1; i <= m; i++)
    {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    bfs(n, graph, vis);
    return 0;
}