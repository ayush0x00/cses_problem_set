#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("test_input.txt","r",stdin);
    #endif

    int t;
    cin>>t;
    while(t--){
      int left,right;
      cin>>left>>right;
      if(left<right) swap(left,right);
      if(left>2*right){
        cout<<"NO\n";
        continue;
      }
      if((left+right)%3==0) cout<<"YES\n";
      else cout<<"NO\n";

    }
    return 0;
}