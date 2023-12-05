#include <bits/stdc++.h>
using namespace std;

void printQ(priority_queue<int> q)
{
    while (!q.empty())
    {
        cout << q.top() << " ";
        q.pop();
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("in.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> deck(n);
        priority_queue<long long> bonus;
        long long card = -1;
        long long power = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> card;

            if (card == 0 && bonus.size() > 0)
            {
                power += bonus.top();
                bonus.pop();
            }
            else if (card > 0)
            {
                bonus.emplace(card);
                // printQ(bonus);
            }
        }
        cout << power << "\n";
    }
}