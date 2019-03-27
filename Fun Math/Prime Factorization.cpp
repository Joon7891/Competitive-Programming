#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0); cout.tie(0);

    int N, x; cin >> N;
    while (N--)
    {
        cin >> x;

        double upper = sqrt(x) + 1;
        for (int i = 2; i < upper; ++i)
        {
            while (!(x % i))
            {
                cout << i << " ";
                x /= i;
            }
        }

        if (x > 1) cout << x;
        cout << endl;
    }
}
