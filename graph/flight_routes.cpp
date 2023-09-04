#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e17;

vector<vector<long long>> dijkstra(int src, const vector<vector<pair<int, int>>> &graph, int k)
{
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    pq.push({0, src});
    vector<vector<long long>> dist(graph.size()+1,vector<long long>(k,INF));
    dist[src][0]=0;
    while (!pq.empty())
    {
        int from = pq.top().second;
        long long d = pq.top().first;
        pq.pop();

        // if(vis[from]) continue;
        if(dist[from][k-1] < d ) continue;
        for(auto nbr:graph[from]){
            int to = nbr.first;
            int cost = nbr.second;
            if(dist[to][k-1]>d+cost){
                dist[to][k-1]=cost+d;
                pq.push({dist[to][k-1],to});
                sort(dist[to].begin(),dist[to].end());
            }
            
        }
    }

    // for(auto i:dist) cout<<i<<" ";

    return dist;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("test_input.txt", "r", stdin);
#endif

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 1; i <= m; i++)
    {
        int from, to, cost;
        cin>>from>>to>>cost;
        graph[from].push_back({to, cost});
    }

    vector<vector<long long>>dist = dijkstra(1,graph,k);
    for(int i=0;i<k;i++){
        cout<<dist[n][i]<<" ";
    }
}