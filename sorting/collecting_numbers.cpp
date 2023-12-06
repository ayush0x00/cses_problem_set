#include <bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<int> rankArr;

void solve()
{
  int n;
  cin >> n;
  vector<int> nums(n + 1);
  int el;
  for (int i = 0; i < n; i++)
  {
    cin >> el;
    nums[el] = i;
  }

  int counter = 1;
  for (int i = 1; i <= n; i++)
  {
    if (nums[i] < nums[i - 1])
      counter++;
  }
  cout << counter << "\n";
}

int main(int argc, char const *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  // freopen("test_input.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
  solve();
  return 0;
}
