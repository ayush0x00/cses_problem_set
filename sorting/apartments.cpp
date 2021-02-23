#include<bits/stdc++.h>
#define ll long long
#define in(arr,n) for(int i=0;i<n;i++) cin>>arr[i];
#define out(arr,n) for(int i=0;i<n;i++) cout<<arr[i]<<" ";
using namespace std;

void solve(){
 ll n_apartments,m_applicants,k;
 cin>>m_applicants>>n_apartments>>k;
 vector<ll> desired_size(m_applicants);
 in(desired_size,m_applicants);
 vector<ll> size_of_apartment(n_apartments);
 in(size_of_apartment,n_apartments);
 sort(desired_size.begin(),desired_size.end());
 sort(size_of_apartment.begin(),size_of_apartment.end());
 ll i=0,j=0,cnt=0;
 while(i<m_applicants && j<n_apartments){
   if(size_of_apartment[j]+k<desired_size[i]) j++;
   else if(size_of_apartment[j]-k>desired_size[i]) i++;
   else{
     i++; j++;cnt++;
   }
 }
 std::cout << cnt << '\n';
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(0);
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w+",stdout);
  #endif
  cin.tie(0);
  solve();
  return 0;
}
