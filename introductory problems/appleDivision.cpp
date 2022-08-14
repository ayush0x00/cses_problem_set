#include <bits/stdc++.h>
using namespace std;

long ans = INT_MAX;
void appleDiv(const vector<long>& nums,int idx, long w1, long w2){

    if(idx==nums.size()){
        ans = min(ans, abs(w1-w2));
        return;
    }

    //putting idx in box 1
    w1+=nums[idx];
    appleDiv(nums,idx+1,w1,w2);
    w1-=nums[idx];

    w2+=nums[idx];
    appleDiv(nums,idx+1,w1,w2);
    w2-=nums[idx];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen ("test_input.txt","r",stdin);
    // freopen ("out.txt","w",stdout);
    int n;
    cin>>n;
    vector<long> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    // vector<int>nums{3,2,7,4,1};
    appleDiv(nums,0,0,0);
    cout<<ans;
    return 0;
}