#include <bits/stdc++.h>
using namespace std;


long long hashFunc(const string& str){
    long long hashVal = 0;
    int p = 31;
    int m = 1e9+7;
    int p_pow = 1;

    for(auto i:str){
        hashVal += ((i-'a'+1)*p_pow)%m;
        p_pow = (p*p_pow%m)%m;
    }

    return hashVal;
}

map<int,long long> prefixHash(const string& s){
    map<int, long long>prefixMap;
    for(int i=0;i<s.length();i++){
        long long hashval = hashFunc(s.substr(0,i+1));
        prefixMap.insert({i,hashval});
    }
    return prefixMap;
}

map<int,long long> suffixHash(const string& s){
    map<int, long long>suffixMap;
    int n = s.length();
    for(int i=n-1;i>=0;i--){
        long long hashval = hashFunc(s.substr(i,n-i));
        suffixMap.insert({i,hashval});
    }
    return suffixMap;
}



void solve(int n, string& str, set<long long>& keyMap){
    string temp = str;
    int count = 0;
    long long totalHash = hashFunc(str);
    auto p = prefixHash(str);
    auto s = suffixHash(str);
    for(int i=0;i<=n-2;i++){
        long long prefix = 
        keyMap.insert(hashVa);
        // str = temp;
    }
    cout<<keyMap.size()<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("in.txt","r",stdin);
    string str="";
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n>>str;
        set<long long> keyMap;
        solve(n,str,keyMap);
    }
}