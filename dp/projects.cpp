#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<vector<long long>>& projects, int idx){
    int low = 0, high = idx-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(projects[mid][1]>=projects[idx][0]) high = mid-1;
        else{
            if(projects[mid+1][1]<projects[idx][0]) low = mid+1;
            else return mid;
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("test_input.txt","r",stdin);
    #endif

    int n;
    cin>>n;
    vector<vector<long long>>projects(n);
    for(int i=0;i<n;i++){
        long long from,to,cost;
        cin>>from>>to>>cost;
        projects[i]={from,to,cost};
    }

    auto cmp = [](vector<long long>&a, vector<long long>&b){
        return a[1]<b[1];
    };

    sort(projects.begin(),projects.end(),cmp);

    vector<long long>dp(n,0);
    dp[0]=projects[0][2];

    for(int i=1;i<n;i++){
        long long incl = projects[i][2];
        int canExcl = binarySearch(projects,i);
        if(canExcl != -1){
            incl += dp[canExcl];
        }
        long long excl = dp[i-1]; 
        dp[i]=max(incl,excl);
    }

    // for(auto i:dp) cout<<i<<" ";
    // cout<<"\n";

    cout<<dp[n-1];
    return 0;

}