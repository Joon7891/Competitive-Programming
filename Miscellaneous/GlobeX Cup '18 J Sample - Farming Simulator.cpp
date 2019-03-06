#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  
  int farms[n];

  for (int i = 0; i < n; ++i)
  {
    cin >> farms[i];
  }

  sort(farms, farms + n);

  long long sum = 0;
  for (int i = m; i < n; ++i)
  {
    sum += farms[i];
  }

  cout << sum << "\n";
}