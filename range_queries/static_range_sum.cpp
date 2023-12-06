#include <bits/stdc++.h>
using namespace std;

void solve(){

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("test_input.txt","r",stdin);
    #endif

    int n,q;
    cin>>n>>q;
    vector<int>nums(n);
    vector<long long>prefix_sum(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    prefix_sum[0]=nums[0];
    for(int i=1;i<n;i++) prefix_sum[i]=prefix_sum[i-1]+nums[i];

    //2,3,4
    //2,5,9
    while(q--){
        int left,right;
        cin>>left>>right;
        // righ = 4 , left = 2
        long long res = prefix_sum[right-1]-prefix_sum[left-1]+nums[left-1];
        cout<<res<<"\n";
    }
}