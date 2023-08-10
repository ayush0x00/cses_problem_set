#include <bits/stdc++.h>
using namespace std;

vector<int>parent_vec;
int cycle_start=-1, cycle_end=-1;
bool dfs(int i, const vector<vector<int>>&graph, vector<int>& vis, int parent){
    
    vis[i]=true;
    for(int nbr:graph[i]){
        if(nbr==parent) continue;
        if(vis[nbr]){
            cycle_start=nbr;
            cycle_end=i;
            return true;
        }
        parent_vec[nbr]=i;
        if(dfs(nbr,graph,vis,parent_vec[nbr])) return true;
    }
    return false;

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif
    int n;
    cin>>n;
    vector<vector<int>>graph(n+1);
    vector<int>vis(n+1,false);
    parent_vec = vector<int>(n+1,-1);
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int from,to;
        cin>>from>>to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i] && dfs(i,graph,vis,parent_vec[i])){
            break;
        }
    }
    if(cycle_start==-1) cout<<"IMPOSSIBLE\n";
    else{
        vector<int>cycle;
        cycle.push_back(cycle_start);
        for(int s=cycle_end;s!=cycle_start;s=parent_vec[s]) cycle.push_back(s);
        cycle.push_back(cycle_start);

        cout<<cycle.size()<<"\n";
        for(auto i:cycle) cout<<i<<" ";
        cout<<"\n";
    }
    return 0;
}