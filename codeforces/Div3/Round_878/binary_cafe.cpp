#include <bits/stdc++.h>
using namespace std;

void solve(int coins,int desserts){
    int sol=0;
    for(int i=0;i<desserts;i++){
        if((coins >= (2^i))){
            sol++;
            coins-=(2^i);
        }
        else break;
    }
    cout<<sol<<"\n";
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
        int coins,desserts;

        cin>>coins>>desserts;
        solve(coins,desserts);
    }

    return 0;
}