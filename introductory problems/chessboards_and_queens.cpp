#include <bits/stdc++.h>
using namespace std;

int ans=0;

void solve(vector<vector<char>>& board,int row,vector<bool>& col, vector<bool>& diag, vector<bool>revDiag){
    if(row==8){
        ans+=1;
        return;
    }

    for(int i=0;i<8;i++){
        if(!col[i] && !diag[row+i] && !revDiag[row-i+board.size()-1] && board[row][i]!='*'){
            col[i] = true;
            revDiag[row-i+board.size()-1] = true;
            diag[row+i]=true;
            solve(board,row+1,col,diag,revDiag);
            col[i]=false;
            revDiag[row-i+board.size()-1] = false;
            diag[row+i]=false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);

    vector<vector<char>> board(8,vector<char>(8));
    for(int i=0;i<8;i++){
        string row;
        cin>>row;
        for(int j=0;j<8;j++){
            board[i][j]=row[j];
        }
    }
    vector<bool>col(board[0].size());
    vector<bool>diag(2*board.size()-1);
    vector<bool>revDiag(2*board.size()-1);

    solve(board,0,col,diag,revDiag);

    cout<<ans<<"\n";

    return 0;
}