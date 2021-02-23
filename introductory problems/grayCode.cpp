#include<bits/stdc++.h>
#define ll long long
#define in(arr,n) for(int i=0;i<n;i++) cin>>arr[i];
#define out(arr,n) for(int i=0;i<n;i++) cout<<arr[i]<<"\n";
using namespace std;

vector<string> solve(int t){
  if (t<=0) return {"0"};
  if (t==1) return {"0","1"};
  vector<string> temp=solve(t-1);
  vector<string> main_ans;
  for(int i=0;i<temp.size();i++) main_ans.push_back("0"+temp[i]);
  for(int i=temp.size()-1;i>=0;i--) main_ans.push_back("1"+temp[i]);
  return main_ans;
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
  vector<string> gray=solve(t);
  out(gray,gray.size())
  return 0;
}
