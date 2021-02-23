#include<bits/stdc++.h>
#define ll long long
#define in(arr,n) for(int i=0;i<n;i++) cin>>arr[i];
#define out(arr,n) for(int i=0;i<n;i++) cout<<arr[i]<<" ";
using namespace std;

void solve(){
  int n;
  cin>>n;
  std::vector<ll> p(n);
  in(p,n);
  sort(p.begin(),p.end());
  ll l1_sum=p[0];
  ll l2_sum=p[1];
  for(int i=2;i<n;i++){
    if(l1_sum<l2_sum) l1_sum+=p[i];
    else l2_sum+=p[i];
  }
  std::cout << abs(l1_sum-l2_sum) << '\n';
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
