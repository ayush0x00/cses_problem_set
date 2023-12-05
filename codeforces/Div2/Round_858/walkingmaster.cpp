#include <bits/stdc++.h>
using namespace std;

void solve(int a,int b,int c,int d){
    if(d<b || (a-b)<(c-d)){
        cout<<"-1\n";
        return;
    }
    cout<<(d-b)+((a+d-b)-c)<<"\n";
    return;
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
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        solve(a,b,c,d);
    }
}