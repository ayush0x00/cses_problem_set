#include <bits/stdc++.h>
using namespace std;

void solve(string s, string t, int k, int n)
{
    for (int i = 0; i < n - k; i++)
    {
        if (s[i] != t[i])
        {
            if (s[i + k] != t[i] && s[i + k + 1] != t[i])
            {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s, t;
        cin >> s >> t;
        solve(s, t, k, n);
    }
}