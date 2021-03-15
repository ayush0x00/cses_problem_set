#include<bits/stdc++.h>
#define ll long long
#define in(arr,n) for(int i=0;i<n;i++) cin>>arr[i];
#define out(arr,n) for(int i=0;i<n;i++) cout<<arr[i]<<" ";
#define lp(i,n) for(int i=0;i<n;i++)
using namespace std;

void solve(){
  ll n;
  cin>>n;
  vector<ll> coin(n);
  in(coin,n);
  sort(coin.begin(),coin.end());
  ll minSum=1;
  for(auto x: coin){
    if(x>minSum) {std::cout << minSum << '\n'; return;}
    else minSum+=x;
  }
  std::cout << minSum << '\n';
  return;
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
