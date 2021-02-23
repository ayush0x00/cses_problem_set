#include<bits/stdc++.h>
#define ll long long
#define in(arr,n) for(int i=0;i<n;i++) cin>>arr[i];
#define out(arr,n) for(int i=0;i<n;i++) cout<<arr[i]<<" ";
using namespace std;

void solve(int n,int from,int to, int aux){
  if(n==1){
    std::cout << from <<" "<<to<< '\n';
    return;
  }
  solve(n-1,from,aux,to);
  std::cout << from <<" "<<to<< '\n';
  solve(n-1,aux,to,from);
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
  #endif
  int n;
  cin>>n;
  std::cout << pow(2,n)-1 << '\n';
  solve(n,1,3,2);
  return 0;
}
