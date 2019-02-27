#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 10000;
vector<int> adj[MAXN];
int dp[MAXN];
int N;

int main()
{
    scanf("%i", &N);

    int a, b;
    scanf("%i %i", &a, &b);
    while (a && b)
    {
        adj[a].push_back(b);
        scanf("%i %i", &a, &b);
    }

    dp[1] = 1;
    for (int i = 1; i <= N; ++i)
    {
        for (int &j : adj[i])
        {
            dp[j] += dp[i];
        }
    }

    cout << dp[N] << endl;
}