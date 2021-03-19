#include<bits/stdc++.h>
#define ll long long
#define in(arr,n) for(int i=0;i<n;i++) cin>>arr[i];
#define out(arr,n) for(int i=0;i<n;i++) cout<<arr[i]<<" ";
#define lp(i,n) for(int i=0;i<n;i++)
using namespace std;

void solve(){
  int n;
  cin>>n;
  std::set<int> v;
  lp(i,n) v.insert(i+1);
  int start=0;
  while(v.size()!=0){
    auto it=v.begin();
    start=(start+1)%v.size();
    advance(it,start);
    std::cout << *it << " ";
    v.erase(it);
  }
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
