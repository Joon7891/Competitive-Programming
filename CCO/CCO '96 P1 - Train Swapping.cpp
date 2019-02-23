#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
int N, T;

const int MAX = 55;
int a[MAX];

int solve()
{
    int counter = 0;

    cin >> T;
    for (int i = 0; i < T; ++i) cin >> a[i];

    for (int i = 1; i < T; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (a[j] > a[i]) ++counter;
        }
    }

    return counter;
}

int main()
{
    cin >> N;
    while (N--)
    {
        printf("Optimal train swapping takes %i swaps.\n", solve());
    }
}
