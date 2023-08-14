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

    string s1,s2;
    cin>>s1>>s2;

    vector<vector<int>>dp(s1.length()+1,vector<int>(s2.length()+1,0));
    for(int i=1;i<=s2.length();i++) dp[0][i] = dp[0][i-1]+1;
    for(int i=1;i<=s1.length();i++) dp[i][0] = dp[i-1][0]+1;

    for(int i=1;i<=s1.length();i++){
        for(int j=1;j<=s2.length();j++){
            if(s1[i-1]==s2[j-1]) {
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                dp[i][j]=min(dp[i][j-1],min(dp[i-1][j-1],dp[i-1][j])) + 1;
            }
        }
    }
    // for(auto i:dp){
    //     for(auto j:i)cout<<j<<" ";
    //     cout<<"\n";
    // }
    cout<<dp[s1.size()][s2.size()]<<"\n";
}