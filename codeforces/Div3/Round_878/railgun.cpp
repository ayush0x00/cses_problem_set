#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif

    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int r;
        cin>>r;
        bool free[n+1][m+1][r+1];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for (int k=0;k<r;k++) free[i][j][k]=true;
            }
        }

        for(int i=0;i<r;i++){
            int t,d,cord;
            cin>>t>>d>>cord;
            if(d==1){
                for(int j=0;j<=m;j++){
                    if(t-cord-j>=0 && t-cord-j<=r) free[cord][j][t-cord-j]=false;
                }
            }
            else{
                for(int j=0;j<=n;j++){
                    if(t-cord-j>=0 && t-cord-j<=r) free[j][cord][t-cord-j]=false;
                }
            }
        }

        bool dp[m+1][n+1][r+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                for(int k=0;k<=r;k++){
                    dp[i][j][k] = !(i || j ||k);
                    if(free[i][j][k]){
                        if(i && dp[i-1][j][k]) dp[i][j][k]=true;
                        if(j && dp[i][j-1][k]) dp[i][j][k]=true;
                        if(k && dp[i][j][k-1]) dp[i][j][k]=true;
                    }
                }
            }
        }
    }
}