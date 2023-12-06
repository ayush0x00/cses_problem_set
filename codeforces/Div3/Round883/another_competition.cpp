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
        int n,m,h;
        cin>>n>>m>>h;
        int ans = 1,rud_point=0;
        long long rud_penalty=0;
        for(int i=0;i<n;i++){
            vector<int>time(m);
            for(int j=0;j<m;j++) cin>>time[j];
            sort(time.begin(),time.end());
            int task = 0;
            int time_taken = 0;
            long long penalty = 0;
            
            for(int t = 0;t<m;t++){
                if(time_taken + time[t]>h) break;
                time_taken += time[t];
                penalty += time_taken;
                task ++;
            }

            if(i!=0){
                if(task>rud_point) ans++;
                if(task==rud_point && penalty < rud_penalty) ans++;
            }
            else{
                rud_point=task;
                rud_penalty=penalty;
            }
        }
        cout<<ans<<"\n";
    }
}