#include <bits/stdc++.h>
using namespace std;

void solve(int city,int k,const vector<int>&fuel,const vector<int>&cost){
    

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif

    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>fuel(n,0);
        vector<int>cost(n,0);
        for(int i=0;i<n;i++) cin>>fuel[i];
        for (int i=0;i<n;i++) cin>>cost[i];
        for(int i=0;i<n;i++){
            solve(i,k,fuel,cost);
        }
    }
    return 0;
}