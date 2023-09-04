#include <bits/stdc++.h>
using namespace std;

const int MAX_L = 20;

int jump(int from, int d,const vector<vector<int>>parent){
    for(int i=0;i<MAX_L;i++){
        if(d & (1<<i)) from = parent[from][i];
    }

    return from;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif

    int n,q;
    cin>>n>>q;
    vector<vector<int>>parent(n+1,vector<int>(MAX_L,-1));
    vector<vector<int>>reach(n+1,vector<int>(MAX_L,-1));
    for(int i=1;i<=n;i++) cin>>parent[i][0];
    for(int d=1;d<MAX_L;d++){
        for(int i=1;i<=n;i++) parent[i][d]=parent[parent[i][d-1]][d-1];
    }

    for(int i=1;i<=n;i++){
        for(int d=0;d<MAX_L;d++){
            reach[i][d]=jump(i,d,parent);
        }
    }

    while(q--){
        int from,to;
        int dist = INT_MAX;
        cin>>from>>to;
        // for(auto i)
    }

}



/*
    Date of journal
*/