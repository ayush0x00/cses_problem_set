#include<bits/stdc++.h>
#define ll long long
#define in(arr,n) for(int i=0;i<n;i++) cin>>arr[i];
#define out(arr,n) for(int i=0;i<n;i++) cout<<arr[i]<<" ";
using namespace std;

void solve(){
  ll n,m;
  cin>>n>>m;
  vector<ll> ticket_price(n);
  in(ticket_price,n);
  vector<ll>max_price(m);
  in(max_price,m);
  multiset<ll> s;
  for(auto i:ticket_price) s.insert(i);
  for(auto i:max_price){
    auto lb=s.lower_bound(i);
    if(*lb==i) {std::cout << i << '\n'; s.erase(lb);}
    else if(lb==s.begin()) {std::cout << "-1" << '\n';}
    else {std::cout << *(--lb) << '\n';s.erase(lb);}
  }
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
  #endif
  int t;
  solve();
  return 0;
}
