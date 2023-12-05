#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>val,int time){
    int i=0,j=0,n=val.size();
    while(j<n && (val[j]-val[i]+1)/2<=time) j++;
    i=j;
    while(j<n && (val[j]-val[i]+1)/2<=time) j++;
    i=j;
    while(j<n && (val[j]-val[i]+1)/2<=time) j++;
    i=j;
    
    return j==n;
}

void solve(int n, vector<int>val){
    int mintime =0,maxtime = 1e9, answer=0;
    
    while(maxtime>=mintime){
        int mid = (maxtime+mintime)/2;
        if(isPossible(val,mid)){
            maxtime = mid-1;
            answer = mid;
        }
        else mintime = mid+1;
    }

    cout<<answer<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>val(n);
        for(int i=0;i<n;i++){
            cin>>val[i];
        }
        sort(val.begin(),val.end());
        solve(n,val);
    }


}