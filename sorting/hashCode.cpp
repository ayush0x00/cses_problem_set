#include<bits/stdc++.h>
#define ll long long
#define in(arr,n) for(int i=0;i<n;i++) cin>>arr[i];
#define out(arr,n) for(int i=0;i<n;i++) cout<<arr[i]<<" ";
#define lp(i,n) for(int i=0;i<n;i++)
using namespace std;

int intersectionSimulated(const auto &car_path, auto &string_no){
  int cars=car_path.size();
  int counter=0;
  vector<vector<int>> visited_path(cars,vector<int>(5));
  for(auto car:car_path){
    for(auto path:car){
      visited_path[counter++][string_no[path]]+=1;
    }
  }
  counter=0;
  for(auto i:visited_path){
    for(auto j:i){
      if(j>1) counter++;
    }
  }
  return counter;
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  #ifndef ONLINE_JUDGE
    freopen("a.txt","r",stdin);
    freopen("out.txt","w",stdout);
  #endif
  ll d,i,s,v,f;
  cin>>d>>i>>s>>v>>f;
  vector<string> string_name(s);
  map<string,int>string_no;
  vector<vector<string>> car_path(v);
  vector<vector<int>> string_info(s,vector<int>(3));
  lp(j,s) cin>>string_info[j][0]>>string_info[j][1]>>string_name[j]>>string_info[j][2];
  lp(j,v) {
    int no_of_streets;
    cin>>no_of_streets;
    std::vector<string> temp(no_of_streets);
    lp(k,no_of_streets){
      cin>>temp[k];
    }
    car_path.push_back(temp);
  }
  int counter=0;
  for(auto name:string_name){
    string_no[name]=counter++;
  }
  int simulations= intersectionSimulated(car_path,string_no);
  std::cout << simulations << '\n';
  return 0;
}
