#include <bits/stdc++.h>
using namespace std;

int buildTower(int h_start, int h_end, int w_start, int w_end){
    if((h_end-h_start==1)&&(w_end-w_start==1)) return 1;
    if(((h_end-h_start)<=0) || ((w_end-w_start)<=0)) return 0;

    int totWays = 0;
    for(int i=h_start;i<h_end;i++){
        int top = buildTower(i,h_end,w_start,w_end);
        int bottom = buildTower(0,i,w_start,w_end);
        totWays += (top+bottom);
    }

    for(int i=w_start;i<w_end;i++){
        int left = buildTower(h_start,h_end,0,i);
        int right = buildTower(h_start,h_end,i,w_end);
    }

    return totWays;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<buildTower(0,n-1,0,2);
    }
    
}