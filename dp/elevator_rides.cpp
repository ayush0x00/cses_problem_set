#include <bits/stdc++.h>
using namespace std;

int getRides(vector<int>&weights, int mask, int time,const int max_load,vector<vector<int>>&dp){
    if(mask==0) return 0;
        if(dp[mask][time]!=-1) return dp[mask][time];
        int ans = INT_MAX;
        for(int i=0;i<weights.size();i++){
            if(mask&(1<<i)){
                if(time + weights[i]<=max_load)
                    ans = min(ans,getRides(weights,mask^(1<<i),time+weights[i],max_load,dp));
                else 
                    ans = min(ans, 1+ getRides(weights,mask^(1<<i),weights[i],max_load,dp));
                
            }
        }
        return dp[mask][time] = ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif
    int n,x;
    cin>>n>>x;
    vector<int>weights(n);
    for(int i=0;i<n;i++) cin>>weights[i]; //BS can also be used
    
    // vector<vector<int>>dp((1<<14),vector<int>( 16,-1)); //Wont work as the capacity of lift is 10^9
    // cout<< getRides(weights,(1<<weights.size())-1,0,x,dp)+1<<"\n";

    int limit = (1<<n); //all possibilities
    vector<pair<long long,long long>>dp(limit);//stores {number_rides, weight_of_last_ride} for each mask
    dp[0]={1,0};
    for(int mask=1;mask<limit;mask++){
        pair<long long, long long>best_res = {INT_MAX,INT_MAX};
        for(int i=0;i<n;i++){
            if( (mask & (1<<i))==0) continue;
            auto prev_state = dp[((1<<i)^ mask)];
            if(prev_state.second + weights[i] <= x){
                prev_state.second += weights[i];
            }
            else{
                prev_state.first += 1;
                prev_state.second = weights[i];
            }

            best_res = min(prev_state,best_res);  
        }
        dp[mask] = best_res;
    }
    cout<<dp[limit-1].first<<"\n";
    return 0;
}