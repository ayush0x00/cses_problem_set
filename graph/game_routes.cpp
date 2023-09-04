#include <bits/stdc++.h>
using namespace std;

int ans=0;

const long long MOD=1e9+7;

int dfs(int src, int dest, vector<int>&vis, const vector<vector<int>>& graph,vector<long long>&dp){
    
    if(src==dest) return dp[src]=1;

    if(dp[src]!=-1) return dp[src];

    vis[src]=true;

    long long len = 0;

    for(auto nbr:graph[src]){
        if(!vis[nbr]) len += (dfs(nbr,dest,vis,graph,dp)%MOD);
    }

    vis[src]=false;
    return dp[src]=len%MOD;
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
    vector<vector<int>>graph(n+1);
    vector<int>vis(n+1);
    vector<long long>dp(n+1,-1);
    for(int i=0;i<m;i++){
        int from,to;
        cin>>from>>to;
        graph[from].push_back(to);
    }

    dfs(1,n,vis,graph,dp);
    // for(auto i:dp) cout<<i<<" ";
    cout<<dp[1]<<"\n";
}