#include <bits/stdc++.h>

using namespace std;
const int MAXN = 200005;

int a[MAXN];
int N;

int main()
{
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> a[i];
    }

    sort(a, a + N);

    int b = 1, c = 1;
    for (int i = 1; i < N; ++i)
    {
        if (a[i] - a[i - c] <= 5)
        {
            c++;
        }
        else
        {
            while (a[i] - a[i - c] < 5)
            {
                c--;
            }
        }

        b = max(b, c);
    }

    cout << b << endl;
}
