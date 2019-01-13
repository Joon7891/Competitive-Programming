#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int m, n, k;
    cin >> m;
    cin >> n;
    cin >> k;

    int dif[m + 1][n + 1];

    for (int i = 0; i < m + 1; ++i)
    {
        for (int j = 0; j < n + 1; ++j)
        {
            dif[i][j] = 0;
        }
    }

    while (k--)
    {
        int x, y, r, b;
        cin >> x >> y >> r >> b;

        // Zero-based
        --x;
        --y;

        int top = max(0, y - r);
        int bottom = min(m - 1, y + r);
        
        int shift, leftX, rightX;
        for (int i = top; i <= bottom; ++i)
        {
            shift = (int)sqrt(r * r - (y - i) * (y - i));
            leftX = max(0, x - shift);
            rightX = min(n - 1, x + shift);

            //cout << "Modifying: (" << leftX << ", " << i << ") (" << rightX + 1 << ", " << i << ") " << b << "\n";

            dif[i][leftX] += b;
            dif[i][rightX + 1] -= b;

            //for (int j = 0; j < m + 1; ++j)
            //{
                //for (int k = 0; k < n + 1; ++k)
                //{
                    //cout << dif[j][k] << " ";
                //}
                //cout << "\n";
            //}
        }
    }

    int maximum = 0;
    int count = 0;
    for (int i = 0; i < m; ++i)
    {
        int current = 0;
        for (int j = 0; j < n; ++j)
        {
            current += dif[i][j];

            if (current == maximum)
            {
                ++count;
            }
            else if (current > maximum)
            {
                maximum = current;
                count = 1;
            }
        }
    }

    cout << maximum << "\n";
    cout << count << "\n";
}