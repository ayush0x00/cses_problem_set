#include <bits/stdc++.h>
using namespace std;

void solve(){

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

    for(int i=1;i<=m;i++){
            int from,to,cost;
        cin>>from>>to>>cost;
        graph[from].push_back({to,cost});
    }

    vector<int>parent(n+1);
    vector<int>back_dist(n+1);
    vector<bool>vis(n+1);
    vector<int>dist(n+1,INT_MAX);
    dist[1]=0;
    priority_queue<pair<int,int>>q;
    q.push({1,0});
    while(!q.empty()){
        int from = q.top().first;
        q.pop();
        if(dist[from]==INT_MAX || vis[from]) continue;
        vis[from]=true;
        for(auto nbr:graph[from]){
            int to = nbr.first;
            int cost = nbr.second;
            if(dist[from]+cost < dist[to]){
                dist[to] = dist[from]+cost;
                q.push({to,dist[to]});
                parent[to]=from;
                back_dist[to]=cost;
            }
        }
    }
    int max_cost  = INT_MIN;
    for(int cur=n;cur!=1;cur=parent[cur]){
        // cout<<cur<<"->";
        max_cost=max(max_cost,back_dist[cur]);
    }
    // cout<<max_cost<<"\n";
    int reduction = max_cost/2;
    // for(auto i:dist) cout<<i<<" ";
    // cout<<"\n";
    cout<<dist[n]-max_cost+reduction<<"\n";
    return 0;
}