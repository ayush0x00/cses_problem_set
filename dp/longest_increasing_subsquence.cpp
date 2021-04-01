#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define in(arr,n) for(int i=0;i<n;i++) cin>>arr[i];
#define out(arr,n) for(int i=0;i<n;i++) cout<<arr[i]<<" ";
#define lp(i,start,end) for(int i=start;i<end;i++)
#define rev_lp(i,start,end) for(int i=start;i>end;i--)
using namespace std;

void strictlylis(){
  ll n;
  cin>>n;
  std::vector<ll> lis;
  lp(i,0,n){
    ll x;
    cin>>x;
    auto it=lower_bound(lis.begin(),lis.end(),x);
    if(it==lis.end()) lis.emplace_back(x);
    else *it=x;
  }
  std::cout << lis.size() << '\n';
}

void lis(){
  ll n;
  cin>>n;
  std::vector<ll> lis;
  lp(i,0,n){
    ll x;
    cin>>x;
    auto it=upper_bound(lis.begin(),lis.end(),x);
    if(it==lis.end()) lis.emplace_back(x);
    else *it=x;
  }
  std::cout << lis.size() << '\n';
}

void naive_implementation(){
  ll n;
  cin>>n;
  std::vector<ll> seq(n);
  in(seq,n);
  std::vector<ll> dp(n,INT_MIN);
  dp[0]=1;
  int overall_max=1;
  lp(i,1,n){
    int max=0;
    lp(j,0,i){
        if(seq[i]>seq[j]){
          if(dp[j]>max) max=dp[j];
        }
      }
      dp[i]=1+max;
      if(dp[i]>overall_max) overall_max=dp[i];
  }
  //std::cout << dp.size() << '\n';
  std::cout << overall_max << '\n';
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
  #endif
  strictlylis();
  return 0;
}
