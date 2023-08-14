#include <bits/stdc++.h>
using namespace std;

pair<long long,long long> getMaxScore(int start, int end, const vector<int>&nums,map<pair<int,int>,pair<long,long>>&dp){

    if(start==end) return {nums[start],0};
    
    if(start>end) return {-1e18,-1e18};

    if(dp.find({start,end})!=dp.end()) return dp[{start,end}];

    pair<long long,long long> pickFirst = getMaxScore(start+1,end,nums,dp);
    pair<long long,long long> pickLast = getMaxScore(start,end-1,nums,dp);

    if(pickFirst.second + nums[start] > pickLast.second + nums[end]) return dp[{start,end}]={pickFirst.second+nums[start],pickFirst.first};
    else return dp[{start,end}]={pickLast.second+nums[end],pickLast.first};
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("test_input.txt","r",stdin);
    #endif
    int n;
    cin>>n;
    vector<int>number_list(n);
    for(int i=0;i<n;i++) cin>>number_list[i];

    // map<pair<int,int>,pair<long,long>>dp;

    vector<vector<pair<long long,long long>>>dp(n,vector<pair<long long,long long>>(n,{-1e18,-1e18}));

    for(int gap=0;gap<n;gap++){
        for(int start=0,end=gap;end<n;start++,end++){
            if(gap==0){
                dp[start][end]={number_list[start],0};
            }
            else{
                pair<long long,long long> pickFirst = dp[start+1][end];
                pair<long long,long long> pickLast = dp[start][end-1];
                if(pickFirst.second + number_list[start] > pickLast.second + number_list[end])  dp[start][end]={pickFirst.second+number_list[start],pickFirst.first};
                else  dp[start][end]={pickLast.second+number_list[end],pickLast.first};
            }
        }
    }
    
    pair<long,long> scores = dp[0][n-1];

    // for(auto i:dp){
    //     for(auto j:i) cout<<"{"<<j.first<<","<<j.second<<"}"<<" ";
    //     cout<<"\n";
    // }
    cout<<scores.first<<"\n";
}