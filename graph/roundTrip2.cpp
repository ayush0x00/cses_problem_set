#include <bits/stdc++.h>
using namespace std;

vector<int>parent;
vector<vector<int>>graph;
vector<int>color;
int cycle_start=-1,cycle_end=-1;
// 0->not visited, 1->visited on same path

bool dfs(int src){
    // visited[src]=true;
    color[src]=1;
    for(auto nbr:graph[src]){
        if(color[nbr]==0){
            parent[nbr]=src;
            if(dfs(nbr)) return true;
        }
        else if(color[nbr]==1){
            cycle_start=nbr;
            cycle_end=src;
            return true;
        }
    }
    color[src]=2;
    return false;
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
    graph = vector<vector<int>>(n+1);
    parent = vector<int>(n+1,-1);
    color = vector<int>(n+1,0);
    for(int i=0;i<m;i++){
        int from, to;
        cin>>from>>to;
        graph[from].push_back(to);
    }

    for(int i=1;i<=n;i++){
        if(color[i]==0 && dfs(i)) break;
    }

    if(cycle_start==-1) cout<<"IMPOSSIBLE\n";
    else{
        vector<int>cycle;
        cycle.push_back(cycle_start);
        for(int i=cycle_end;i!=cycle_start;i=parent[i]) cycle.push_back(i);
        cycle.push_back(cycle_start);
        reverse(cycle.begin(),cycle.end());
        cout<<cycle.size()<<"\n";
        for(auto i:cycle) cout<<i<<" ";
        cout<<"\n";
    }
}