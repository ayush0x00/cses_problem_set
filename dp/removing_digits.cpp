#include <bits/stdc++.h>
using namespace std;

int getSteps(int number,vector<int>&memo){
    if(number==0) return 0;
    if(number<0) return INT_MAX;
    if(memo[number]!=-1) return memo[number];
    int ans = INT_MAX;
    int temp=number;
    while(temp>0){
        int dig = temp%10;
        if(dig!=0) ans = min(ans,getSteps(number-dig,memo)+1);
        temp/=10;
    }
    return memo[number]=ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif

    int n;
    cin>>n;
    vector<int>memo(n+1,-1);
    cout<<getSteps(n,memo)<<"\n";

}