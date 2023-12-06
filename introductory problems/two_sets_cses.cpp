#include <bits/stdc++.h>
#define ll long long
#define in(arr, n)            \
  for (int i = 0; i < n; i++) \
    cin >> arr[i];
#define out(arr, n)           \
  for (int i = 0; i < n; i++) \
    cout << arr[i] << " ";
using namespace std;

bool flag = false;
vector<int> set1;
vector<int> set2;

int main(int argc, char const *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
#endif
  int t;
  cin >> t;
  if ((t * (t + 1)) % 4 != 0)
  {
    cout << "NO\n";
    return 0;
  }

  vector<long long> s1;
  vector<long long> s2;
  if (t % 2 == 0)
  {
    for (int i = 0; i < t / 2; i++)
    {
      if (i % 2 == 0)
      {
        s1.push_back(i + 1LL);
        s1.push_back(t - i);
      }
      else
      {
        s2.push_back(i + 1LL);
        s2.push_back(t - i);
      }
    }
  }
  else
  {
    for (int i = 0; i < t / 2; i++)
    {
      if (i % 2 == 0)
      {
        s1.push_back(i + 1LL);
        s1.push_back(t - i-1);
      }
      else
      {
        s2.push_back(i + 1LL);
        s2.push_back(t - i-1);
      }
    }
    if (t % 2 == 1)
      s2.push_back(t);
    else
      s1.push_back(t);
  }

  cout << "YES\n";
  cout << s1.size() << "\n";
  for (auto i : s1)
    cout << i << " ";
  cout << "\n"
       << s2.size() << "\n";
  for (auto i : s2)
    cout << i << " ";
  return 0;
}
