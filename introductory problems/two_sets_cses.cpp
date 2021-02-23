#include<bits/stdc++.h>
#define ll long long
#define in(arr,n) for(int i=0;i<n;i++) cin>>arr[i];
#define out(arr,n) for(int i=0;i<n;i++) cout<<arr[i]<<" ";
using namespace std;

void solve(const int& n){
  int target=n*(n-1)/2;
  if(target%2!=0){ cout<<"NO"<<endl; return;}
  target/=2;
  vector<vector<int>> dp(n,vector<int>(target+1,0));

}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
  #endif
  int t;
  cin>>t;
  solve(t);
  return 0;
}
