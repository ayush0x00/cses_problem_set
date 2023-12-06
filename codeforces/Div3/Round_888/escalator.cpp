#include <bits/stdc++.h>
using namespace std;


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
        int n,m,k,h;
        cin>>n>>m>>k>>h;
        vector<int>height(n);
        for(int i=0;i<n;i++) cin>>height[i];
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(abs(height[i]-h)%k==0 && (abs(height[i]-h))/k <= (m-1) && h!=height[i]) cnt++;
        }
        cout<<cnt<<"\n";
    }
}