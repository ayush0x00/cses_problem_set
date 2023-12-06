#include <bits/stdc++.h>
using namespace std;


int main(){
    map<int,int>test;

    test.insert({2,4});
    test.insert({5,6});

    for(auto i:test) test[i.first]++;
    for(auto i:test) cout<<i.first<<" "<<i.second<<"\n";
}