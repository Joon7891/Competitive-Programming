#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int MAXN = 100005;

bool aft[MAXN];
bool cur[MAXN];
LL N, T;

LL getJump()
{
    LL ans = 1;
    for (int i = 0; i < 62; ++i)
    {
        ans <<= 1;

        if (ans > T)
        {
            ans >>= 1;
            return (LL)ans;
        }
    }

    return (LL)ans;
}

int main()
{
    cin >> N >> T;

    string line;
    cin >> line;

    for (int i = 0; i < N; ++i)
    {
        cur[i] = line[i] == '1';
    }

    while (T)
    {
        LL jump = getJump();

        for (int i = 0; i < N; ++i)
        {
            LL left = (i - jump % N + N) % N;
            LL right = (i + jump % N) % N;
            aft[i] = cur[left] ^ cur[right];
        }

        copy(aft, aft + N, cur);
        T -= jump;
    }

    for (int i = 0; i < N; ++i) cout << cur[i];
    cout << "\n";
}