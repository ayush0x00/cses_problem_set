#include <bits/stdc++.h>
using namespace std;

auto comp=[](vector<int>&a, vector<int>&b){
    return a[2]<b[2];
};

vector<int>parent;
vector<int>rank_size;

int find_par(int x){
    if(x==parent[x]) return x;
    return parent[x]=find_par(parent[x]);
}

void union_find(int x, int y){
    int par_x = find_par(x), par_y = find_par(y);
    if(par_x!=par_y){
        if(rank_size[x]>rank_size[y]) parent[par_y]=par_x;
        else if(rank_size[x]<rank_size[y]) parent[par_x] = par_y;
        else{
            parent[par_x]=par_y;
            rank_size[par_y]++;
        }
    }
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
    parent = vector<int>(n+1,-1);
    rank_size = vector<int>(n+1,0);
    for(int i=1;i<=n;i++) parent[i]=i;

    vector<vector<int>>edges;
    for(int i=1;i<=m;i++){
        int from,to,cost;
        cin>>from>>to>>cost;
        edges.push_back({from,to,cost});
    }
    sort(edges.begin(),edges.end(),comp);
    long long min_cost = 0;
    int edge_count = 0;
    for(auto e:edges){
        int v1 = e[0], v2=e[1],cost=e[2];
        if(find_par(v1)!=find_par(v2)){
            min_cost+=cost;
            union_find(v1,v2);
            edge_count+=1;
        }
    }
    if(edge_count!=n-1){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    cout<<min_cost<<"\n";
}