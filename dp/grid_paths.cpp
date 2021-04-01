#include<bits/stdc++.h>
#define ll long long
#define in(arr,n) for(int i=0;i<n;i++) cin>>arr[i];
#define out(arr,n) for(int i=0;i<n;i++) cout<<arr[i]<<" ";
#define lp(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
using namespace std;

void solve(){
  int n;
  cin>>n;
  vector<string> grid;
  lp(i,n){
    string temp;
    cin>>temp;
    grid.emplace_back(temp);
  }
  vector<vector<ll>> dp(n,(vector<ll>(n,0)));
  if(grid[n-1][n-1]=='*') {
    std::cout << "0" << '\n';
    return;
  }
  else dp[n-1][n-1]=1;
  for(int i=n-2;i>-1;i--){
    grid[i][n-1]=='*'?dp[i][n-1]=0:dp[i][n-1]=dp[i+1][n-1];
  }
  for(int i=n-2;i>-1;i--){
    grid[n-1][i]=='*'?dp[n-1][i]=0:dp[n-1][i]=dp[n-1][i+1];
  }
  for(int i=n-2;i>-1;i--){
    for(int j=n-2;j>-1;j--){
      grid[i][j]=='*'?dp[i][j]=0 : dp[i][j]=(dp[i][j+1]%mod+dp[i+1][j]%mod)%mod;
    }
  }
  /*for(auto i:dp){
    for(auto j:i) std::cout << j ;
    std::cout << '\n';
  }*/
  std::cout << dp[0][0]%mod << '\n';
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
