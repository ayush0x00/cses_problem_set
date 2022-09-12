#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void dfs(int r, int c, vector<vector<bool>> &visited, const vector<vector<char>> &grid)
{
    if (r >= grid.size() || r < 0 || c >= grid[0].size() || c < 0 || visited[r][c] || grid[r][c] == '#')
        return;
    visited[r][c] = true;
    for (auto mv : moves)
        dfs(r + mv.first, c + mv.second, visited, grid);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("in.txt", "r", stdin);
    int r, c;
    cin >> r >> c;
    vector<vector<char>> grid(r, vector<char>(c));
    vector<vector<bool>> visited(r, vector<bool>(c));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            cin >> grid[i][j];
    }
    int answer = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (!visited[i][j] && grid[i][j] == '.')
            {
                dfs(i, j, visited, grid);
                answer++;
            }
        }
    }
    cout << answer << "\n";
    return 0;
}