#include <bits/stdc++.h>
using namespace std;

int ans =0;
vector<pair<int,int>>dir = {{1,0},{0,1},{-1,0},{0,-1}};
void path(int idx,int r, int c, string query,vector<vector<bool>>&vis){
    if(r==7 && c==1){
        ans+= (idx==48);
        cout<<ans<<"\n";
        return;
    }
    if(r<0 || c<0 || r>=7 || c>=7 || vis[r][c]){
        return;
    }
    

    char ch = query[idx];
    // cout<<ch;
    vis[r][c]=true;
    if(ch!='?'){
        int x = r, y=c;
        if(ch=='D') x++;
        else if(ch=='R') y++;
        else if(ch=='L') y--;
        else x--;
         path(idx+1,x,y,query,vis);
        
    }
    else{
        for(auto d:dir){
            int nr = r+d.first;
            int nc = c+d.second;
             path(idx+1,nr,nc,query,vis);
        }
    }
    vis[r][c]=false;
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif

    string str;
    cin>>str;
    vector<vector<bool>>vis(7, vector<bool>(7,false));
    path(0,0,0,str,vis);
    cout<<ans<<"\n";


}