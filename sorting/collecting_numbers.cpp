#include<bits/stdc++.h>
#define ll long long
#define in(arr,n) for(int i=0;i<n;i++) cin>>arr[i];
#define out(arr,n) for(int i=0;i<n;i++) cout<<arr[i]<<" ";
#define lp(i,n) for(int i=0;i<n;i++)
using namespace std;

void solve(){
  ll n;
  cin>>n;
  vector<ll>v(n);
  in(v,n);
  set<ll> result;
  result.insert(v[0]);
  for(auto i:v){
    auto it=result.begin();
    if(i<(*it)) result.insert(i);
  }
  std::cout << result.size() << '\n';
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  #ifndef ONLINE_JUDGE
    freopen("test_input.txt","r",stdin);
    freopen("out.txt","w",stdout);
  #endif
  solve();
  return 0;
}
