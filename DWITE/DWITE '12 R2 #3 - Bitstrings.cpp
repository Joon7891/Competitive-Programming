#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

unordered_map<int, int> memo;

int s(int a)
{
    if (a == 0 || a == 1 || a == 2) return 1;
    if (memo[a]) return memo[a];
    
    return memo[a] = s(a - 2) + s(a - 3);
}

int main()
{
    for (int i = 0, x; i < 5; ++i)
    {
        cin >> x;
        cout << s(x) << endl;
    }
    
    return 0;
}
