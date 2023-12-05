#include <bits/stdc++.h>
using namespace std;
vector<long long>weight;
vector<long long>par;

long long solve(int x, int y, vector<unordered_map<long long, long long>> &m)
{
    if (x == 0)
        return 0;
    if (m[x][y]==0)
    {
        m[x][y] = weight[x]*weight[y] + solve(par[x],par[y],m);
    }

    return m[x][y];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif

    int n, q;
    cin >> n >> q;
    weight = vector<long long>(n + 1);
    par = vector<long long>(n + 1);
    vector<unordered_map<long long, long long>> m(n + 1);
    par[1] = 0;
    for (long long i = 1; i <= n; i++)
        cin >> weight[i];
    for (long long i = 2; i <= n; i++)
        cin >> par[i];
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        cout<<solve(x, y, m)<<"\n";
    }
}