#include <bits/stdc++.h>
using namespace std;
int MOD=1e9+7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif

    int amnt, n;
    cin>>n>>amnt;
    vector<int>coins(n);
    for(int i=0;i<n;i++) cin>>coins[i];

    vector<int>prev(amnt+1),curr(amnt+1);
    prev[0]=curr[0]=1;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=amnt;j++){
            curr[j] = prev[j]%MOD;
            if(j>=coins[i-1]) curr[j]+=(curr[j-coins[i-1]])%MOD;
        }
        prev=curr;
        curr=vector<int>(amnt+1);
        curr[0]=1;
    }
    cout<<prev[amnt]%MOD<<"\n";
    return 0;
}