#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10); cout.setf(ios::fixed);

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif

    int t;
    cin >> t;
    while (t--)
    {
        int n, d, h;
        cin >> n >> d >> h;
        vector<int> y(n);
        for (int i = 0; i < n; i++)
            cin >> y[i];
        long double ans = (long double)d * h / 2.0;
        for (int i = 0; i < n - 1; i++)
        {
            if (y[i + 1] >= y[i] + h)
                ans += (long double)d * h / 2.0;
            else
            {
                long double s1 = (long double)d * (y[i] + h - y[i + 1]) / h;
                long double ph = y[i + 1] - y[i];
                ans += (s1 + d) / 2.0 * ph;
            }
        }
        cout << ans << "\n";
    }
}