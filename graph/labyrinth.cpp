#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> moves{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
string dir = "DRUL";

vector<vector<int>> prevpath;

bool isValid(int r, int c, const vector<vector<char>> &grid)
{
    if (r >= grid.size() || r < 0 || c >= grid[0].size() || c < 0 || grid[r][c] == '#')
        return false;
    return true;
}

void bfs(queue<vector<int>> &bfsQueue, const vector<vector<char>> &grid, vector<vector<bool>> &visited)
{
    while (!bfsQueue.empty())
    {
        auto nodeInfo = bfsQueue.front();
        bfsQueue.pop();
        int r = nodeInfo[0], c = nodeInfo[1], d = nodeInfo[2];

        if (grid[r][c] == 'B')
        {
            cout << "YES\n";
            cout << d << "\n";

            string path = "";
            while (prevpath[r][c] != -1)
            {
                path += dir[prevpath[r][c]];
                pair<int, int> prevMove = moves[(prevpath[r][c] + 2) % 4];
                r += prevMove.first;
                c += prevMove.second;
            }
            reverse(path.begin(), path.end());
            cout << path << "\n";
            return;
        }
        for (int dir = 0; dir < 4; dir++)
        {
            pair<int, int> i = moves[dir];
            int nr = r + i.first;
            int nc = c + i.second;
            if (isValid(nr, nc, grid) && visited[nr][nc] == false)
            {
                visited[r][c] = true;
                bfsQueue.push({nr, nc, d + 1});
                prevpath[nr][nc] = dir;
            }
        }
    }
    cout << "NO\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("test_input.txt", "r", stdin);
    int r, c;
    cin >> r >> c;

    int rs, cs;
    vector<vector<char>> grid(r, vector<char>(c));
    vector<vector<bool>> visited(r, vector<bool>(c, false));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> grid[i][j];

            if (grid[i][j] == 'A')
            {
                rs = i;
                cs = j;
            }
        }
    }

    queue<vector<int>> q;
    q.push({rs, cs, 0});
    prevpath = vector<vector<int>>(r, vector<int>(c, 5));
    prevpath[rs][cs] = -1;
    visited[rs][cs] = true;
    bfs(q, grid, visited);
}