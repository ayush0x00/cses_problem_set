#include <bits/stdc++.h>

using namespace std;

void solve(int n, string s){
    string res = "";
    for(int i=0,j=1;i<n;){
        if(j>n) break;
        if(s[i]==s[j]){
            res += s[i];
            i=j+1;
            j = i+1;
        }
        else{
            j++;
        }
    }
    cout<<res<<"\n";
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
        int n;
        cin>>n;
        string s;
        cin>>s;
        solve(n,s);
    }

    return 0;
}