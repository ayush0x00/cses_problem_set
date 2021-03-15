#include<bits/stdc++.h>
#define ll long long
#define in(arr,n) for(int i=0;i<n;i++) cin>>arr[i];
#define out(arr,n) for(int i=0;i<n;i++) cout<<arr[i]<<" ";
#define MAX 1e9
#define lp(i,n) for(int i=0;i<n;i++)
using namespace std;

void solve(){
 ll n;
 cin>>n;
 vector<ll>v(n);
 ll k;
 map<ll,ll> freq;
 lp(i,n){
   cin>>k;
   v[i]=k; freq.insert({k,-1});
 }
 ll max_size=1,start=0;
 lp(end,n){
   //if element is not found in freq

   start=max(start,freq[v[end]]+1);
   //if element is found in freq
   max_size=max(max_size,end-start+1);
   freq[v[end]]=end;
 }
 std::cout << max_size << '\n';
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
