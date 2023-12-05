#include <bits/stdc++.h>
using namespace std;

// USING DSU
vector<int> parent;
vector<int> rankArray;

int find_parent(int v)
{
    if (parent[v] == v)
        return v;
    return parent[v] = find_parent(parent[v]);
}

void union_set(int a, int b)
{
    a = find_parent(a);
    b = find_parent(b);

    if (a != b)
    {
        if (rankArray[a] > rankArray[b])
        {
            parent[b] = a;
            rankArray[a]++;
        }
        else
        {
            parent[a] = b;
            rankArray[b]++;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("in.txt", "r", stdin);
    int n, r;
    cin >> n;
    parent = vector<int>(n + 1);
    rankArray = vector<int>(n + 1, 1); //modified rank
    for (int i = 1; i <= n; i++)
        parent[i] = i;
    cin >> r;
    int from, to;
    for (int i = 0; i < r; i++)
    {
        cin >> from >> to;
        union_set(from, to);
    }

    int answer = 0;
    int prevComp = find_parent(1);
    vector<pair<int, int>> roads;
    for (int i = 1; i <= n; i++)
    {
        if (parent[i] == i)
        {
            if (prevComp != parent[i])
            {
                roads.push_back({prevComp, i});
            }
            answer++;
        }
    }

    cout << answer - 1 << "\n";
    for (auto i : roads)
        cout << i.first << " " << i.second << "\n";
}