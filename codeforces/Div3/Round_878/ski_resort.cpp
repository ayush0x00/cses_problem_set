#include <bits/stdc++.h>
using namespace std;


void solve(long long n,long long k, long long q,vector<long long>& temp){
    long long len =0, ways=0;
    for (auto i:temp){
        if(i<=q){
            len++;
        }
        else{
            if(len>=k){
                ways += ((len-k+1)*(len-k+2))/2;
            }
            len = 0;
        }
    }
    if(len>=k) ways += ((len-k+1)*(len-k+2))/2;
    cout<<ways<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif

    long long t;
    cin>>t;
    while (t--)
    {
        long long n,k,q;
        cin>>n>>k>>q;
        vector<long long>temp(n);
        for(int i=0;i<n;i++){
            cin>>temp[i];
        }

        solve(n,k,q,temp);
        // cout<<ways<<"\n"
    }
    
    return 0;
}