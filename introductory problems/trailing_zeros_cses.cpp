#include <bits/stdc++.h>
#define ll long long
#define m 1000000007;

using namespace std;
int main(int argc, char const *argv[]) {
  ll n;
  cin>>n;
  int count0=0;
  for(ll i=5;n/i>=1;i*=5) count0+=n/i;
  cout<<count0 << '\n';
  return 0;
}
