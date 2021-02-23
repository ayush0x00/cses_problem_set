#include<bits/stdc++.h>
#define ll long long
#define in(arr,n) for(int i=0;i<n;i++) cin>>arr[i];
#define out(arr,n) for(int i=0;i<n;i++) cout<<arr[i]<<" ";
#define lp(i,n) for(int i=0;i<n;i++)
using namespace std;

void solve(){
  ll n,s;
  cin>>n>>s;
  multiset<ll> ledger;
  vector<ll> values(n);
  in(values,n);
  lp(i,n){
    auto it=ledger.find(values[i]);
    if(it==ledger.end()) ledger.insert(s-values[i]);
    else{
      auto pos=find(values.begin(),values.end(),s-(*it))-values.begin();
      std::cout << pos+1 <<" "<<i+1<< '\n';
      return;
    }
  }
  std::cout << "IMPOSSIBLE" << '\n';
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
