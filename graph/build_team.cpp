#include <bits/stdc++.h>
using namespace std;

void dfs(int src, int c, vector<bool> &vis, vector<int> &colour, const vector<vector<int>> &graph)
{
    if (vis[src])
        return;
    colour[src] = c;
    vis[src] = true;
    for (int nbr : graph[src])
    {
        if (!vis[nbr])
        {
            dfs(nbr, 1 - c, vis, colour, graph);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif

    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    vector<bool> vis(n + 1);
    vector<int> color(n + 1, -1);
    for (int i = 1; i <= m; i++)
    {
        int n1, n2;
        cin >>n1>>n2;
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            dfs(i, 0, vis, color, graph);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int nbr : graph[i])
        {
            if (color[i] == color[nbr])
            {
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        }
    }

    for(int i=1;i<=n;i++) cout<<color[i]+1<<" ";
    return 0;
}