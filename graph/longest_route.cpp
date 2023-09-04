#include <bits/stdc++.h>
using namespace std;

long long NINF=-1e17;

long long ans = NINF;
int dfs(int src, const int dest, const vector<vector<int>>& graph,vector<int>&vis,vector<int>&next,vector<int>&dp)
{
    if(dp[src]!=-1) return dp[src];
    vis[src]=1;
    if(src==dest){
        vis[src]=0;
        return 1;
    }
    
    long long max_dist = NINF;
    for(auto nbr:graph[src]){
        if(!vis[nbr]){
            long long d = dfs(nbr,dest,graph,vis,next,dp);
            if(d+1>max_dist){
                max_dist=d+1;
                next[src]=nbr;
            }
        }
    }
    vis[src]=0;
    return dp[src]=max(max_dist,NINF);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("test_input.txt", "r", stdin);
#endif

    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    vector<int>dp(n+1,-1);
    vector<int>vis(n+1);
    vector<int>par(n+1,-1);
    for (int i = 0; i < m; i++)
    {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
    }

    ans = dfs(1,n,graph,vis,par,dp);

    if(ans<0){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }

   

    vector<int>path;
    int curr=1;
    while(curr!=n){
        path.push_back(curr);
        curr=par[curr];
    }
    path.push_back(n);
    cout<<path.size()<<"\n";
    // reverse(path.begin(),path.end());
    for(auto i:path) cout<<i<<" ";
    cout<<"\n";
    return 0;

}