#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e17;
vector<vector<int>> edges;
vector<int> parent;
vector<long long> dist;

int n, m;

int bellmanFord(int src,vector<bool>&vis)
{
    dist[src] = 0;
    vis[src]=true;
    int x;
    for (int i = 1; i <= n; i++)
    {
        bool anyRelaxation = false;
        x = -1;
        for (auto e : edges)
        {
            int from = e[0], to = e[1], cost = e[2];
            if (dist[from] >= INF)
                continue;
            if (dist[from] + cost < dist[to])
            {
                dist[to] = max(-INF, dist[from] + cost);
                parent[to] = from;
                anyRelaxation = true;
                vis[to]=true;
                x = from;
            }
        }
        if (!anyRelaxation)
            break;
    }

    return x;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        edges.push_back({from, to, cost});
    }
    parent = vector<int>(n + 1);
    dist = vector<long long>(n + 1, INF);
    vector<bool>vis(n+1);

    int cyc;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            cyc = bellmanFord(i,vis);
            if(cyc!=-1) break;
        }
    }

    if(cyc==-1){
        cout<<"NO\n";
        return 0;
    }

    int y = cyc;
    for (int i = 1; i <= n; i++)
        y = parent[y];
    vector<int> path;
    for (int curr = y;; curr = parent[curr])
    {
        if (curr == y && path.size() > 1)
        {
            path.push_back(y);
            break;
        };
        path.push_back(curr);
    }
    // path.push_back(y);
    reverse(path.begin(), path.end());
    cout << "YES\n";
    for (auto i : path)
        cout << i << " ";
}