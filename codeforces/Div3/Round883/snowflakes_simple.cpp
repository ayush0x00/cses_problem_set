#include <bits/stdc++.h>
using namespace std;

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
        long long n;
        cin >> n;
        if (n < 7)
        {
            cout << "NO"
                 << "\n";
        }
        else
        {
            bool flag = false;

            for (int k = 2; k <= 1000; k++)
            {
                long long ans = (k * k) + k + 1;
                if (flag)
                    break;
                if (ans > n)
                    break;
                if (ans == n)
                {
                    flag = true;
                    break;
                }
                long long pow_so_far = k * k;
                for (int p = 3; p <= 60; p++)
                {
                    pow_so_far = pow_so_far * k;
                    if(pow_so_far>1e18) break;
                    ans += pow_so_far;
                    if (ans > 1e18)
                        break;
                    if (ans == n)
                    {
                        flag = true;
                        break;
                    }
                }
            }
            if (flag)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}