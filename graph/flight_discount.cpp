#include <bits/stdc++.h>
using namespace std;

const long long INF=1e17;

auto comp = [](pair<int,int>&a, pair<int,int>&b){
    return a.second > b.second;
};

vector<long long> dijkstra(int src,const vector<vector<pair<int,int>>>&graph){
    vector<long long>dist(graph.size()+1,INF);
    dist[src]=0;
    vector<bool>vis(graph.size()+1);
    priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>pq;
    pq.push({0,src});

    while(!pq.empty()){
        int from = pq.top().second;
        pq.pop();
        if(vis[from] || dist[from]==INF) continue;
        vis[from]=1;
        for(auto nbr:graph[from]){
            int to=nbr.first;
            long long cost = nbr.second;
            if(dist[to]>dist[from]+cost){
                dist[to]=dist[from]+cost;
                dist[to]=min(dist[to],INF);
                pq.push({dist[to],to});
            }
        }
    }

    return dist;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("test_input.txt","r",stdin);
    #endif

    int n,m;
    cin>>n>>m;

    vector<vector<pair<int,int>>>graph(n+1);
    vector<vector<pair<int,int>>>rev_graph(n+1);
    vector<vector<int>>edges;

    for(int i=1;i<=m;i++){
        int from,to,cost;
        cin>>from>>to>>cost;
        graph[from].push_back({to,cost});
        rev_graph[to].push_back({from,cost});
        edges.push_back({from,to,cost});
    }

    vector<long long>dist = dijkstra(1,graph);
    vector<long long>rev_dist = dijkstra(n,rev_graph);

    long long ans=INF;
    for(auto e:edges){
        int from = e[0],to=e[1],cost=e[2];
        ans=min(ans, dist[from]+cost/2+rev_dist[to]);
    }

    cout<<ans<<"\n";
    
    return 0;
}