#include <bits/stdc++.h>
using namespace std;

// map<string, long long> stringPrefixHash;
long long stringPrefixHash[1000007];
vector<long long> p_power;
vector<int> res;
const long long m = 1e9 + 7;

void generatePower(int n, int p)
{
    p_power = vector<long long>(n);
    p_power[0] = 1;
    for (int i = 1; i <= n; i++)
        p_power[i] = (p * p_power[i - 1]) % m;
}

long long computeHash(string s)
{
    long long hash = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (i == 0)
            stringPrefixHash[i] = 0;
        else
        {
            stringPrefixHash[i] = (stringPrefixHash[i - 1] + (s[i] - 'a' + 1) * p_power[i]) % m;
        }
    }
    return 0;
}
void solve(string s)
{
    for (int i = 1; i < s.length(); i++)
    {
        long long suffHash = (stringPrefixHash[s.length() - 1] + m - ((p_power[i] * stringPrefixHash[s.length() - i - 1]) % m) + m) % m;
        // cout << suffHash << " " << i << "\n";
        if (stringPrefixHash[i] == suffHash && i + 1 != s.length() - 1)
        {
            cout << i << " ";
            res.push_back(s.length() - i);
        }
    }
    reverse(res.begin(), res.end());
    for (auto i : res)
        ;
    // cout << i << " ";
}

void printHash()
{
    for (int i = 0; i < 11; i++)
        cout << stringPrefixHash[i] << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    generatePower(s.length(), 31);
    computeHash(s);
    solve(s);
    return 0;
}