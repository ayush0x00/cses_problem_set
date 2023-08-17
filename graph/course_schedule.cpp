#include <bits/stdc++.h>
using namespace std;

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
    vector<vector<int>>graph(n+1);
    vector<bool>vis(n+1);
    vector<int>indegree(n+1);
    for(int i=0;i<m;i++){
        int from, to;
        cin>>from>>to;
        graph[from].push_back(to);
        indegree[to]++;
    }

    queue<int>nodes;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0) nodes.push(i);
    }
    vector<int>path;
    while(!nodes.empty()){
        int curr=nodes.front();
        path.push_back(curr);
        nodes.pop();
        vis[curr]=true;
        for(auto nbr:graph[curr]){
            if(vis[nbr]) continue;
            indegree[nbr]--;
            if(indegree[nbr]==0) nodes.push(nbr);
        }
    }
    if(path.size()!=n) cout<<"IMPOSSIBLE\n";
    else{
        for(auto i:path) cout<<i<<" ";
        cout<<"\n";
    }
}