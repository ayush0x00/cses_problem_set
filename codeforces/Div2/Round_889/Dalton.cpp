#include <bits/stdc++.h>
using namespace std;

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
        int ans=0;
        int temp = 0;
        bool toSwap=false;
        for(int i=1;i<=n;i++){
            cin>>temp;
            if(temp==i){
                if(toSwap){
                    ans++;
                    toSwap=false;
                }
                else toSwap=true;
            }
        }
        if(toSwap) ans++;
        //
        // if(ans%2==0) ans=ans/2;
        // else ans=(ans/2)+1;
        cout<<ans<<"\n";
    }
    return 0;
}