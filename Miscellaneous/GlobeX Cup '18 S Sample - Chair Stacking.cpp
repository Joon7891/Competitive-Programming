#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0); 
  int n;
  int pointer;
  cin >> n;

  pointer = (n - 1) / 2;

  int xArray[n];
  int yArray[n];

  int x, y;
  for (int i = 0; i < n; ++i)
  {
    cin >> x >> y;
    xArray[i] = x;
    yArray[i] = y;
  }

  sort(xArray, xArray + n);
  sort(yArray, yArray + n);

  int xMid = xArray[pointer], yMid = yArray[pointer];

  long long total = 0;
  for (int i = 0; i < n; ++i)
  {
    total += abs(xMid - xArray[i]) + abs(yMid - yArray[i]);
  }

  cout << total << "\n";
}