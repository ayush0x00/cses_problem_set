#include <bits/stdc++.h>
using namespace std;

const int MOD=1e9+7;

int solve(int i, int n, int sum, int curr_sum,vector<vector<int>>&dp){
    if(i>n) return curr_sum==sum;
    if(dp[i][curr_sum]!=-1) return dp[i][curr_sum];
    int take = solve(i+1,n,sum,curr_sum+i,dp)%MOD;
    int not_take = solve(i+1,n,sum,curr_sum,dp)%MOD;
    return dp[i][curr_sum]=(take+not_take)%MOD;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // #ifndef ONLINE_JUDGE
    //     freopen("in.txt","r",stdin);
    // #endif

    int n;
    cin>>n;

    vector<vector<int>>dp(n+1,vector<int>(70000,-1));

    int sum = n*(n+1)/2;
    if(sum%2!=0){
        cout<<"0\n";
        return 0;
    }

    if(n==1){
        cout<<"0\n";
        return 0;
    }
    if(n==2){
        cout<<"1\n";
        return 0;
    }
    dp[1][1]=0;
    dp[2][1]=0,dp[2][2]=0,dp[2][3]=0;
    int ways = solve(1,n,sum/2,0,dp)%MOD;
    cout<<ways<<"\n";
    return 0;
}