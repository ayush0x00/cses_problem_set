#include<bits/stdc++.h>
#define ll long long
#define in(arr,n) for(int i=0;i<n;i++) cin>>arr[i];
#define out(arr,n) for(int i=0;i<n;i++) cout<<arr[i]<<" ";
#define lp(i,n) for(int i=0;i<n;i++)
using namespace std;

void solve(){
  string first,second;
  cin>>first>>second;
  int len1=first.length(), len2=second.length();
  int dp[len1][len2];
  lp(i,len1){
    lp(j,len2){
      if(i==0 || j==0) {dp[i][j]=0; continue;}
      if(first[i]==second[j]) dp[i][j]=1+dp[i-1][j-1];
      else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
  }
  std::cout << dp[len1-1][len2-1]+1 << '\n';
  //printing the longest common sequence

}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--) solve();
  return 0;
}
