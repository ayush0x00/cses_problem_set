#include<bits/stdc++.h>
#define ll long long
#define in(arr,n) for(int i=0;i<n;i++) cin>>arr[i];
#define out(arr,n) for(int i=0;i<n;i++) cout<<arr[i]<<" ";
#define lp(i,n) for(int i=0;i<n;i++)
using namespace std;

bool cmp(const pair<ll,ll>&a, const pair<ll,ll>&b){
  return(b.second>a.second);
}

void solve(){
  ll n;
  cin>>n;
  vector<pair<ll,ll>> s;
  lp(i,n){
    ll a,b;
    cin>>a>>b;
    s.push_back({a,b});
  }
  sort(s.begin(),s.end(),cmp);
  ll ans=0,temp=0,i=0;
  while(i<n){
    if(temp<=s[i].first){
      temp=s[i].second;
      ans++;i++;
    }
    else i++;
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
