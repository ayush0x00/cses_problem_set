#include <bits/stdc++.h>
using namespace std;

vector<int> prefixFunction(string s){
    int n = s.length();
    vector<int>pi(n,0);

    for(int i=1;i<n;i++){
        int j= pi[i-1];
        while(j>0 && s[i]!=s[j]) j= pi[j-1];
        if(s[i]==s[j]) j++;
        pi[i]=j;
    }
    return pi;
}

void getCount(string s, string pat){
    int ans = 0;
    string comb = pat+"#"+s;
    vector<int> pi = prefixFunction(comb);
    int n = pat.length();
    for(auto l:pi){
        if(l==n) ans++;
    }
    cout<<ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    string pat;
    cin>>s>>pat;
    getCount(s,pat);
    return 0;
}