#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>&f,int k){
    int brawls=0;
    
    for(int i=0;i<26;i++){
        if(f[i+26] != 0 && f[i]!=0){
            if(f[i]==f[i+26]){
                brawls += f[i];
                f[i]=f[i+26]=0;
                continue;
            }
            if(f[i]>f[i+26]){
                f[i] -= f[i+26];
                brawls+=f[i+26];
                f[i+26] = 0;
            }
            else{
                f[i+26] -= f[i];
                brawls += f[i];
                f[i] = 0;
            }
        }
    }
    // for(auto i: f) cout<<i<<" ";
    for(int i=0;i<f.size();i++){
        if(k==0) break;
        if(f[i]==0) continue;
        int conv = floor(f[i]/2);
        if(conv <= k){
            k-=conv;
            brawls+=conv;
            f[i] -= 2*conv;
        }
        else{
            brawls += k;
            k=0;  
            f[i] -= 2*conv;
        }
    }
    cout<<brawls<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("in.txt","r",stdin);
    int n;
    cin>>n;
    while(n--){
        int l,k;
        cin>>l>>k;
        vector<int> freqCount(53,0);
        char ch = ' ';
        for(int i=0;i<l;i++){
            cin>>ch;
            if(ch<97){
                freqCount[ch-'A']++;
            }
            else{
                freqCount[ch-'a'+26]++;
            }
        }
        solve(freqCount,k);
        
    }
}