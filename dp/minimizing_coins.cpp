#include<bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define in(arr,n) for(int i=0;i<n;i++) cin>>arr[i];
#define out(arr,n) for(int i=0;i<n;i++) cout<<arr[i]<<" ";
#define lp(i,b,n) for(int i=b;i<n;i++)
using namespace std;

void solve(void){
  int t;ll s;
  cin>>t>>s;
  std::vector<ll> coins(t);
  in(coins,t);
  std::vector<ll> dp(s+1,INT_MAX);
  dp[0]=0;
  lp(i,1,s+1){
    for(int j=0;j<t;j++){
      if(coins[j]>i) continue;
      dp[i]=min(dp[i],1+dp[i-coins[j]]);
    }
  }
  //for(auto i:dp) std::cout << i << '\n';
  if(dp[s]==INT_MAX) std::cout << "-1" << '\n';
  else std::cout << dp[s] << '\n';
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
  #endif
  solve();
  return 0;
}
