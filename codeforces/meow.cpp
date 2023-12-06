#include <bits/stdc++.h>
using namespace std;

void solve(int n, string s)
{
    vector<char> small{'m', 'e', 'o', 'w'};

    string temp = "";
    for (auto i : s)
    {
        if (i < 97)
            temp += i + 32;
        else
            temp += i;
    }

    int idx = 0;
    char prev = ' ';

    string finalC = "";
    for(auto i:temp){
        if(prev==' ' || prev != i){
            finalC += i;
            prev = i;
        }
    }
    if(finalC=="meow") cout<<"YES\n";
    else cout<<"NO\n";
    // for (auto i : temp)
    // {
    //    if(i==small[idx]){
    //     prev = idx;
    //     idx++;
    //    }
    //    else if (prev != -1 && i==small[prev]) continue;
    //    else{
    //     cout<<"NO\n";
    //     return;
    //    }
    // }
}

int main()
{
    // freopen("in.txt", "r", stdin);
    int test;
    cin >> test;

    while (test--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        solve(n, s);
    }
}