#include <bits/stdc++.h>
using namespace std;

set<string>res;
vector<string>resDistinct;
void solve(string s, string curr){
    if(s.length()==0){
        res.insert(curr);
        return;
    }

    for(int i=0;i<s.length();i++){
        char ch = s[i];
        string lpart = s.substr(0,i);
        string rpart = s.substr(i+1,s.length()-i);
        solve(lpart+rpart,curr+ch);
    }
}

map<char,int> generateHashMap(const string &ques){
    map<char,int> freqMap;
    for(auto i : ques) freqMap[i]++;
    return freqMap;
}

void PermuteDistinct(const string &ques, int n, int curr, map<char,int>&freqMap, string asf){

    if(asf.length()==n){
        resDistinct.push_back(asf);
        return;
    }

    for(auto i: freqMap){
        if(i.second > 0){
            freqMap[i.first]--;
            PermuteDistinct(ques,n,curr+1,freqMap,asf+i.first); //making call to next level
            freqMap[i.first]++;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // freopen ("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    // solve(s,"");
    map<char,int> freqMap = generateHashMap(s);
    PermuteDistinct(s,s.length(),0,freqMap,"");
    cout<<resDistinct.size()<<"\n";
    for(auto i:resDistinct) cout<<i<<"\n";
    return 0;
}