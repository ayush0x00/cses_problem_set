#include <bits/stdc++.h>
using namespace std;

int count_int(int a , int b){
    if(a==b) return 0;
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif

    int a, b;
    cin>>a>>b;
    cout<<count_int(a,b);
}