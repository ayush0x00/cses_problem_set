#include<bits/stdc++.h>
#define ll long long
#define in(arr,n) for(int i=0;i<n;i++) cin>>arr[i];
#define out(arr,n) for(int i=0;i<n;i++) cout<<arr[i]<<" ";
using namespace std;

void solve(){
 ll n,x;
 cin>>n>>x;
 std::vector<ll> child(n);
 in(child,n);
 ll gondolas=0;
 sort(child.begin(),child.end());
 std::vector<ll> temp=child;
 ll i=0,j=n-1;
 while(i<=j){
   if(i==j) {gondolas++; break;}
   else if(child[i]+child[j]>x){j--;gondolas++;}
   else{gondolas++;i++;j--;}
 }
 std::cout << gondolas << '\n';
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
