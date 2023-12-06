#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int ans = 0;
        int a, b;
        for (int i = 0; i < n; i++)
        {
            cin >> a >> b;
            if (a - b > 0)
                ans++;
        }
        cout << ans << "\n";
    }
}