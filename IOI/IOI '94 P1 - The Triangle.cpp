#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < n; ++i)
#define endl "\n"

using namespace std;

const int MAXN = 100;
int tree[MAXN][MAXN];
int memo[MAXN][MAXN];
int n;

int solve(int level, int indexNo)
{
    if (level == n - 1)
    {
        return tree[level][indexNo];
    }
    else if (memo[level][indexNo] != -1)
    {
        return memo[level][indexNo];
    }
    else
    {
        int answer = tree[level][indexNo] + max(solve(level + 1, indexNo), solve(level + 1, indexNo + 1));
        memo[level][indexNo] = answer;
        return answer;
    }
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(memo, -1, sizeof(memo));

    cin >> n;

    forn(i, n)
    {
        forn(j, i + 1)
        {
            cin >> tree[i][j];
        }
    }

    cout << solve(0, 0) << endl;
}