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
        string val;
        unordered_map<int, int> seq;

        cin >> val;
        for(auto i:val) seq[(int)i]++;
        
        // for (auto i : seq)
        //     cout << i.first << " " << i.second << "\n";
        if (seq.size() == 4 || seq.size() == 3)
        {
            cout << "4\n";
        }
        else if (seq.size() == 2)
        {
            bool firstPat = true;
            for (auto i : seq)
            {
                if (i.second == 2)
                {
                    firstPat = false;
                }
            }

            if (firstPat)
            {
                cout << "6\n";
            }
            else
            {
                cout << "4\n";
            }
        }
        else
        {
            cout << "-1\n";
        }
    }
    return 0;
}