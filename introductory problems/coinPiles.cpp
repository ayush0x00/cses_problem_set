#include<bits/stdc++.h>
#define ll long long
#define in(arr,n) for(int i=0;i<n;i++) cin>>arr[i];
#define out(arr,n) for(int i=0;i<n;i++) cout<<arr[i]<<" ";
using namespace std;

void solve(ll &a, ll &b){
    if((a==0 && b==0) || (a==2 && b==1) || (a==1 && b==2)) {std::cout << "YES" << '\n';return;}
    ll a1=2*b-a;
    ll a2=2*a-b;
    if((a1>0&&a1%3==0) && (a2>0 && a2%3==0))std::cout << "YES" << '\n';
    else std::cout << "NO" << '\n';
    return;
}


int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
  #endif
  ll t;
  cin>>t;
  while(t--) {
    ll a,b;
    cin>>a>>b;
    solve(a,b);

  }
  return 0;
}
