// BRUTE-FORCE approach

#include <bits/stdc++.h>
using namespace std;

bool containedInRange(int n, const vector<pair<int, int>> &ranges, int idx)
{
    pair<int, int> val = ranges[idx];
    for (int i = 0; i < n; i++)
    {
        if (i == idx)
            continue;
        if (val.first >= ranges[i].first && val.second <= ranges[i].second)
            return true;
    }
    return false;
}

bool containsRange(int n, const vector<pair<int, int>> &ranges, int idx)
{
    pair<int, int> val = ranges[idx];
    for (int i = 0; i < n; i++)
    {
        if (i == idx)
            continue;
        if (val.first <= ranges[i].first && val.second >= ranges[i].second)
            return true;
    }
    return false;
}

void solve(int n, const vector<pair<int, int>> &ranges)
{
    for (int i = 0; i < n; i++)
    {
        if (containsRange(n, ranges, i))
            cout << "1"
                 << " ";
        else
            cout << "0"
                 << " ";
    }
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        if (containedInRange(n, ranges, i))
            cout << "1"
                 << " ";
        else
            cout << "0"
                 << " ";
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("in.txt", "r", stdin);

    int n;
    cin >> n;
    vector<pair<int, int>> ranges(n);

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        ranges[i] = {x, y};
    }
    solve(n, ranges);
    return 0;
}