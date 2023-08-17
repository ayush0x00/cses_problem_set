#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
const long long NINF = -1e18;

void solve(){

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif

    int n,m;
    cin>>n>>m;
    vector<vector<int>>edges;
    for(int i=0;i<m;i++){
        int from,to,cost;
        cin>>from>>to>>cost;
        edges.push_back({from,to,-1*cost});
    }
    vector<long long>dist(n+1,INF);

    dist[1]=0;
    for(int i=1;i<=n;i++){
        for(auto e:edges){
            int from = e[0],to=e[1],cost=e[2];
            if(dist[from]==INF) continue;
            dist[to] = min(dist[to],dist[from]+cost);
            dist[to] = max(dist[to],NINF);
        }
    }

    for(int i=1;i<=n;i++){
        for(auto e:edges){
            int from =e[0],to=e[1],cost=e[2];
            if(dist[from]==INF) continue;
            dist[to]=max(dist[to],NINF);
            if(dist[to]>dist[from]+cost) dist[to]=NINF;
        }
    }

    if(dist[n]==NINF) cout<<"-1\n";
    else cout<<-1*dist[n]<<"\n";
    return 0;
    
}