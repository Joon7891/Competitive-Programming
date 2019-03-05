#include <bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;
int N, counter = 0;

int main()
{
    cin >> N;

    int p = -1, c;
    while (N--)
    {
        cin >> c;

        if (c ^ p) counter++;
        p = c;
    }

    cout << counter << endl;
}
