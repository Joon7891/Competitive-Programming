#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main()
{
    int j;
    cin >> j;
    --j;

    int combo = (j * (j - 1) * (j - 2)) / 6;
    if (combo < 0) combo = 0;

    cout << combo << endl;
}
