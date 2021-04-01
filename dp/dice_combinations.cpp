#include<bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define in(arr,n) for(int i=0;i<n;i++) cin>>arr[i];
#define out(arr,n) for(int i=0;i<n;i++) cout<<arr[i]<<" ";
#define lp(i,b,n) for(int i=b;i<n;i++)
using namespace std;

ll solve(ll t){
  std::vector<ll> dp(t+1,0);
  dp[0]=dp[1]=1;
  lp(i,2,t+1){
    for(ll j=i,flag=0;j>0 && flag<6;j--,flag++){
      dp[i]=(dp[i]%MOD + dp[j-1]%MOD)%MOD;
    }
  }
  //for(auto i: dp) std::cout << i << '\n';
  return dp[t]%MOD;
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
  #endif
  ll t;
  cin>>t;
  ll res=solve(t);
  std::cout << res << '\n';
  return 0;
}
