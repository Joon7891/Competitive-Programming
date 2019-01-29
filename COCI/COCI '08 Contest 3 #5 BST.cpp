#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);    

  //BST
  map<int, int> tree;

  //Tree iterator pointer
  map<int, int>::iterator iterPoint;

  int n, current;

  cin >> n;

  long long int counter = 0;

  for (int i = 0; i < n; ++i)
  {
    int depth = 0;
    
    cin >> current;

    iterPoint = tree.lower_bound(current);

    
    if (iterPoint != tree.end())
    {
      depth = max(depth, iterPoint->second + 1);
    }

    if (iterPoint != tree.begin())
    {
      depth = max(depth, (--iterPoint)->second + 1);
    }

    tree[current] = depth;

    counter += depth;

    cout << counter << "\n";
  }

  return 0;
}