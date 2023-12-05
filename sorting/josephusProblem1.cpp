#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define in(arr, n)              \
    for (int i = 0; i < n; i++) \
        cin >> arr[i];
#define out(arr, n)             \
    for (int i = 0; i < n; i++) \
        cout << arr[i] << " ";

int solve(int n, int k)
{
    set<int> temp;
    for (int i = 1; i <= n; i++)
    {
        temp.insert(i);
    }
    int startPos = 0;
    int elmToRm = 0;
    while (temp.size() > 1)
    {
        startPos %= temp.size();
        elmToRm = (startPos + k) % temp.size();
        startPos = elmToRm;
        auto t = temp.find_by_order(elmToRm);
        cout
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif

    solve(7, 1);
    return 0;
}