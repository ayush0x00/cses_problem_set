#include <bits/stdc++.h>
using namespace std;

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
    for(int i=0;i<m;i++){
        int from,to,dist;
        cin>>from>>to>>dist;
        graph[from].push_back({to,dist});
    }

    vector<long long>dist(n+1,1e18);
    dist[1]=0;
    vector<bool>vis(n+1);
    auto comp = [](pair<long long, long long>&a, pair<long long,long long>&b){
        return a.first>b.first;
    };
    
    priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,decltype(comp)>dist_node(comp);
    dist_node.push({0,1});


    
    while(!dist_node.empty()){
        int src = dist_node.top().second;
        dist_node.pop();
        if(vis[src]) continue;
        vis[src]=true;
        for(auto nbr:graph[src]){
            int nxt = nbr.first;
            long long cost = nbr.second;

            if(dist[src]+cost < dist[nxt]) {
                dist[nxt] = dist[src]+cost;
                dist_node.push({dist[nxt],nxt});
            }
        }
    }

    for(int i=1;i<=n;i++) cout<<dist[i]<<" ";
    cout<<"\n";
}