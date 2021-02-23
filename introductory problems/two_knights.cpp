#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin>>n;
  for(int i=1;i<=n;i++){
    ll total_possible_ways=(pow(i,2)*(pow(i,2)-1))/2;
    ll ways_not_to_atack=4*(i-1)*(i-2);
    std::cout << total_possible_ways-ways_not_to_atack << '\n';
  }
}
