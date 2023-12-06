#include <bits/stdc++.h>
using namespace std;

int max_l=30;

int back_jump(int n, int d,const vector<vector<int>>&parent){
    
    for(int i=0;i<max_l;i++){
        if(d&(1<<i)) n=parent[n][i];
    }

    return n;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("test_input.txt","r",stdin);
    #endif

    int n,q;
    cin>>n>>q;
    vector<vector<int>>parent(n+1,vector<int>(max_l));
    for(int i=1;i<=n;i++){
        cin>>parent[i][0];
    }

    for(int d=1;d<max_l;d++){
        for(int j=1;j<=n;j++){
            parent[j][d]=parent[parent[j][d-1]][d-1];
        }
    }

    while(q--){
        int from,dist;
        cin>>from>>dist;
        cout<<back_jump(from,dist,parent)<<"\n";
    }
}