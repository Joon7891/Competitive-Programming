#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < n; ++i)
#define MEM(a, b) memset(a, b, sizeof(a))
#define debug() cout << "..." << endl
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define pb push_back
#define endl "\n"
#define f first
#define s second
#define MAXN 2000001

using namespace std;

const int MAX = 2005;
int lengthCount[MAX];
int comboCount[2 * MAX];

int main()
{
    MEM(lengthCount, 0);

    int n;
    cin >> n;

    int newLength;
    forn(i, n)
    {
        cin >> newLength;
        ++lengthCount[newLength];
    }

    for (int i = 0; i < MAX; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            int length = i + j;

            int combo;

            if (i == j)
            {
                combo = lengthCount[i] / 2;
            }
            else
            {
                combo = min(lengthCount[i], lengthCount[j]);
            }
            comboCount[length] += combo;
        }
    }

    int bestLength = 1;
    int currentCounter = 0;

    for (int i = 1; i < 2 * MAX; ++i)
    {
        if (comboCount[i] == bestLength)
        {
            ++currentCounter;
        }
        else if (comboCount[i] > bestLength)
        {
            bestLength = comboCount[i];
            currentCounter = 1;
        }
    }

    cout << bestLength << " " << currentCounter << endl;
}