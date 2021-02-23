#include<bits/stdc++.h>
#define ll long long
#define in(arr,n) for(int i=0;i<n;i++) cin>>arr[i];
#define out(arr,n) for(int i=0;i<n;i++) cout<<arr[i]<<" ";
using namespace std;


int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
  #endif
  ll t;
  cin>>t;
  std::vector<ll>a(t) ;
  in(a,t);
  set<ll> dist;
  for(auto n:a) dist.insert(n);
  std::cout << dist.size() << '\n';
  return 0;
}
