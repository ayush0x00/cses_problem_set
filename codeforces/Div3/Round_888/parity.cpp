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
        int n;
        cin>>n;
        vector<int>store(n);
        for(int i=0;i<n;i++) cin>>store[i];
        vector<int>temp = store;
        sort(temp.begin(),temp.end());
        bool possible=true;

        for(int i=0;i<n;i++){
            if(store[i]%2!=temp[i]%2){
                possible=false;
                break;
            }
        }

        if(possible) cout<<"YES\n";
        else cout<<"NO\n";
    }
}