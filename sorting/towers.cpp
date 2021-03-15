#include<bits/stdc++.h>
#define ll long long
#define in(arr,n) for(int i=0;i<n;i++) cin>>arr[i];
#define out(arr,n) for(int i=0;i<n;i++) cout<<arr[i]<<" ";
#define lp(i,n) for(int i=0;i<n;i++)
using namespace std;

void solve(){
  int n;
  cin>>n;
  ll k;
  multiset<ll> towers;
  for(int i=0;i<n;i++){
    cin>>k;
    auto it=towers.upper_bound(k);
    if(it==towers.end()) towers.insert(k);
    else{
      towers.erase(it);
      towers.insert(k);
    }
  }
  std::cout << towers.size() << '\n';
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
