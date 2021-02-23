#include<bits/stdc++.h>
#define ll long long
#define in(arr,n) for(int i=0;i<n;i++) cin>>arr[i];
#define out(arr,n) for(int i=0;i<n;i++) cout<<arr[i]<<" ";
#define lp(i,n) for(int i=0;i<n;i++)
using namespace std;

void solve(){
  ll n;
  cin>>n;
  set<pair<ll,ll>> s;
  lp(i,n) {
    ll a,b;
    cin>>a>>b;
    s.insert({a,1});
    s.insert({b,-1});
  }
  ll ans=0,sum=0;
  for(auto i:s){
    //std::cout << i.first <<" "<<i.second<< '\n';
    sum+=i.second;
    ans=max(ans,sum);
  }
  std::cout << ans << '\n';
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
