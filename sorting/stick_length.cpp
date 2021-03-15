#include<bits/stdc++.h>
#define ll long long
#define in(arr,n) for(int i=0;i<n;i++) cin>>arr[i];
#define out(arr,n) for(int i=0;i<n;i++) cout<<arr[i]<<" ";
#define lp(i,n) for(int i=0;i<n;i++)
using namespace std;

void solve(){
  ll n;
  cin>>n;
  std::vector<ll> v(n);
  in(v,n)
  sort(v.begin(),v.end());
  ll median=n/2;
  ll ans=0;
  lp(i,n){
    if(i==median) continue;
    else ans+=(abs(v[median]-v[i]));
  }
  cout<<ans<<"\n";
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
