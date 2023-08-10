#include <bits/stdc++.h>
using namespace std;

vector<pair<pair<int,int>,char>>direction = {{{1,0},'D'},{{0,1},'R'},{{-1,0},'U'},{{0,-1},'L'}};
vector<vector<int>>monsterReachTime;
vector<string>graph;
vector<vector<char>>path;
int end_row,end_col;

bool isValid(int r, int c, int time){
    if( r<0 || c<0 || c>=monsterReachTime[0].size() || r>=monsterReachTime.size() || time>=monsterReachTime[r][c] || graph[r][c]=='#') return false;
    return true;
}

bool canEscape(int r, int c, int time){
    if(!isValid(r,c,time)) return false;
    if(graph[r][c]=='.' && (r==0 || c==0 || r==graph.size()-1 || c==graph[0].length()-1)) return true;
    return false;
}

void multiSourceBFS(const vector<pair<int,int>>&monsterLoc){
    queue<pair<pair<int,int>,int>>cord;
    for(auto i:monsterLoc) cord.push({i,0});
    while(!cord.empty()){
        auto new_cord=cord.front();
        int time = new_cord.second;
        cord.pop();
        for(auto dir:direction){
            int nr= new_cord.first.first+dir.first.first;
            int nc=new_cord.first.second+dir.first.second;
            if(isValid(nr,nc,time+1)) {
                monsterReachTime[nr][nc]=time+1;
                cord.push({{nr,nc},time+1});
            }
        }
    }
}

bool canEscape(int start_r, int start_c){
    queue<pair<pair<int,int>,int>>esc_cord;
    esc_cord.push({{start_r,start_c},0});

    vector<vector<bool>>vis(graph.size(),vector<bool>(graph[0].length(),false));
    while(!esc_cord.empty()){
        int time = esc_cord.front().second;
        int row =esc_cord.front().first.first;
        int col = esc_cord.front().first.second;
        vis[row][col]=true;
        esc_cord.pop();
        for(auto dir:direction){
            int nr=row+dir.first.first;
            int nc= col+dir.first.second;
            char ch=dir.second;
            if(canEscape(nr,nc,time+1) && !vis[nr][nc]){
                path[nr][nc]=ch;
                end_row=nr;
                end_col=nc;
                return true;
            }

            if(isValid(nr,nc,time+1) && !vis[nr][nc]){
                path[nr][nc]=ch;
                esc_cord.push({{nr,nc},time+1});
            }
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif

    int n,m;
    cin>>n>>m;
    monsterReachTime = vector<vector<int>>(n,vector<int>(m,INT_MAX));
    path=vector<vector<char>>(n,vector<char>(m,'*'));
    vector<pair<int,int>>monsterLoc;
    int player_row=-1,player_col=-1;
    
    for(int i=0;i<n;i++){
        string r="";
        for(int j=0;j<m;j++){
            char ch;
            cin>>ch;
            r+=ch;
            if(ch=='M') {
                monsterLoc.push_back({i,j});
                monsterReachTime[i][j]=0;
            }
            else if(ch=='A') {
                player_row=i;
                player_col=j;
                if(i==0 || j==0 || i==n-1 || j==m-1){
                    cout<<"YES\n";
                    cout<<"0\n";
                    return 0;
                }
                path[i][j]='@';
            }
        }
        graph.push_back(r);
    }

    multiSourceBFS(monsterLoc);
    bool esc = canEscape(player_row,player_col);
    if(esc){
        cout<<"YES\n";
        string p="";
        pair<int,int>start_cord={player_row,player_col};
        for(int i=end_row,j=end_col;;){
            char ch=path[i][j];
            if(i==player_row && j==player_col) break;
            p+=ch;
            if(ch=='R') j--;
            else if(ch=='D') i--;
            else if(ch=='L') j++;
            else i++;
        }
        cout<<p.length()<<"\n";
        reverse(p.begin(),p.end());
        cout<<p<<"\n";

    }
    else cout<<"NO\n";
    return 0;
}