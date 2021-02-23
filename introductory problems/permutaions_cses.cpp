#include <iostream>
#include <vector>
using namespace std;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0);
#define ll long long

int main(int argc, char const *argv[]) {
  ll n;
  cin>>n;
  ll temp=n;
  bool no_sol=false;
  vector<ll> beautiful(n);
  if(n==2|| n==3) {
    cout<<"NO SOLUTION"<<endl;
    no_sol=true;
  }
  else{
    if(n%2==0){
      for(int i=1;i<n;i+=2) beautiful[i]=temp--;
      for(int i=0;i<n;i+=2) beautiful[i]=temp--;
    }
    else{
      for(int i=0;i<=n;i+=2) beautiful[i]=temp--;
      for(int i=1;i<n;i+=2) beautiful[i]=temp--;
    }
  }
  if(!no_sol) for(ll i : beautiful) cout<<i<<" ";
  cout<<endl;
  return 0;
}
