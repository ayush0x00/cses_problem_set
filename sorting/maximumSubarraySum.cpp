#include<bits/stdc++.h>
#define ll long long
#define in(arr,n) for(int i=0;i<n;i++) cin>>arr[i];
#define out(arr,n) for(int i=0;i<n;i++) cout<<arr[i]<<" ";
#define lp(i,n) for(int i=0;i<n;i++)
#define MIN 1e-9;
using namespace std;

void solve(){
  ll n;
  cin>>n;
  std::vector<ll> value(n);
  in(value,n);
  ll sum=value[0],sum_so_far=value[0];
  for(int i=1;i<n;i++){
    if(sum>=0) sum+=value[i];
    else sum=value[i];
    if(sum_so_far<sum) sum_so_far=sum;
  }
  std::cout << sum_so_far << '\n';
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
