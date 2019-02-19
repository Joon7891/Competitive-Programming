#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
int N, K;

const int MAXN = 105;
int a[MAXN];

const int MAXK = 100005;
bool win[MAXK];

int main()
{
    memset(win, false, sizeof(win));

    cin >> N >> K;

    for (int i = 0; i < N; ++i)
    {
        cin >> a[i];
    }

    for (int i = 0; i < a[0]; ++i)
    {
        win[i] = false;
    }

    for (int i = a[0]; i <= K; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (a[j] > i) continue;
            win[i] |= !win[i - a[j]];
        }
    }

    if (win[K])
    {
        cout << "First" << endl;
    }
    else
    {
        cout << "Second" << endl;
    }
}
