#include <bits/stdc++.h>
using namespace std;

int mod = 1e9+7;

int getArrays(int idx, int last_placed, int maxVal, int n, const vector<int> &arr, vector<vector<int>>&dp)
{

    if (last_placed == 0 || last_placed == maxVal + 1)
        return 0;
    if (idx == 0)
    {
        if (arr[idx] == 0 || arr[idx] == last_placed)
            return 1;
        else
            return 0;
    }

    if(dp[idx][last_placed]!=-1) return dp[idx][last_placed];

    if (arr[idx] == 0 || arr[idx] == last_placed)
    {
        int left = (getArrays(idx - 1, last_placed - 1, maxVal, n, arr,dp))%mod;
        int no_place = (getArrays(idx - 1, last_placed, maxVal, n, arr,dp))%mod;
        int right = (getArrays(idx - 1, last_placed + 1, maxVal, n, arr,dp))%mod;
        return dp[idx][last_placed] = (((left + no_place)%mod) + right)%mod;
    }
    else if (arr[idx] != 0 && arr[idx] != last_placed)
        return dp[idx][last_placed]=0;
    return dp[idx][last_placed]=0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("test_input.txt", "r", stdin);
#endif
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    long long ans = 0;
    for (int i = 1; i <= m; i++)
    {
        int a= ((getArrays(n - 1, i, m, n, arr,dp))%mod);
        ans+=(a%mod);
    }
    cout << ans%mod << "\n";
}