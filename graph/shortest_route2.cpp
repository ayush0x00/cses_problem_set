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

    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<long long>>graph(n+1,vector<long long>(n+1,1e17));
    for(int i=0;i<m;i++){
        int from,to;
        long long cost;
        cin>>from>>to>>cost;
        long long prev_val = graph[from][to];
        graph[from][to]= min(prev_val, cost);
        graph[to][from]=min(prev_val, cost);
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) graph[i][j]=0;
        }
    }

    for(int via=1;via<=n;via++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                graph[i][j]=min(graph[i][j],graph[i][via]+graph[via][j]);
            }
        }
    }

    while(q--){
        int qfrom,qto;
        cin>>qfrom>>qto;
        long long dist = graph[qfrom][qto];
        if(dist<1e17) cout<<dist<<"\n";
        else cout<<"-1\n";
    }


}