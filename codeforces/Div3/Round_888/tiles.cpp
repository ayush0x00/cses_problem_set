#include <bits/stdc++.h>
using namespace std;

void solve(){

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif

    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>c(n);
        vector<int>freq(n+1,-1);
        for(int i=0;i<n;i++) cin>>c[i];

        for(int i=0;i<n;i++){
            if(freq[c[i]]==-1){
                int cnt = count(c.begin()+i,c.end(),c[i]);
                // cout<<cnt;
                freq[c[i]]=cnt;
            }
        }

        for(auto i:freq) cout<<i<<" ";

        if(freq[c[0]]>=k && freq[c[n-1]]>=k) cout<<"YES\n";
        else cout<<"NO\n";

    }
}