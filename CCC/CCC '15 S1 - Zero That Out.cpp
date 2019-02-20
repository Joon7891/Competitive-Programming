#include <bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

const int MAXN = 100005;
int a[MAXN];
int N;

int main()
{
    cin >> N;

    int index = 0;
    while (N--)
    {
        cin >> a[index++];
        if (a[index - 1] == 0) index -= 2;
    }

    int total = 0;
    for (int i = 0; i < index; ++i)
    {
        total += a[i];
    }

    cout << total << endl;
}
