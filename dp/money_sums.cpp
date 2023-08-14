#include <bits/stdc++.h>
using namespace std;

set<int>ans;
void solve(int idx,const vector<int>& nums,int sum){
    if(idx==nums.size()){
        if(sum!=0) ans.insert(sum);
        return;
    }
    sum+=nums[idx];
    solve(idx+1,nums,sum);
    sum-=nums[idx];
    solve(idx+1,nums,sum);

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif

    int n;
    cin>>n;
    vector<int>coins(n);
    for(int i=0;i<n;i++) cin>>coins[i];
    int maxSum = accumulate(coins.begin(),coins.end(),0);
    vector<vector<bool>>dp(n+1,vector<bool>(maxSum+1,0));
    // int prefix = 0;
    for(int i=1;i<=n;i++){
        // prefix += coins[i-1];
        for(int j=1;j<=dp[0].size();j++){
            if(coins[i-1]>j) dp[i][j]=dp[i-1][j];
            else if(coins[i-1]==j) dp[i][j]=true;
            else{
                dp[i][j] = dp[i-1][j-coins[i-1]] || dp[i-1][j];
            }
        }
    }
    int cnt = count(dp[n].begin(),dp[n].end(),1);
    cout<<cnt<<"\n";
    for(int i=0;i<=dp[n].size();i++){
        if(dp[n][i]) cout<<i<<" ";
    }
    cout<<"\n";

}