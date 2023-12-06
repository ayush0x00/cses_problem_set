#include <bits/stdc++.h>
using namespace std;

const int MAX_LOG = 31, max_n = 1e5+7;
vector<int>bin_log;
vector<vector<int>>pow_log;

int solve(int l, int r){

    int max_pow2 = bin_log[r-l+1];
    return min(pow_log[l-1][max_pow2],pow_log[r-(1<<max_pow2)][max_pow2]);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif

    int n,q;
    cin>>n>>q;

    vector<int>nums(n);
    bin_log = vector<int>(n+1);
    bin_log[0]=0;
    bin_log[1]=0;

    for(int i=2;i<=n;i++) bin_log[i]=1+bin_log[i/2]; 
    pow_log = vector<vector<int>>(n+1,vector<int>(31));

    for(int i=0;i<n;i++){
        cin>>nums[i];
        pow_log[i][0]=nums[i];
    }

    for(int j=1;j<MAX_LOG;j++){
        for(int i=0;i+(1<<j)-1<n;i++){
            pow_log[i][j] = min(pow_log[i][j-1],pow_log[i+(1<<(j-1))][j-1]);
        }
    }

    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<solve(l,r)<<"\n";
    }

}