#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    int counter = 0;

    for (int i = 1; i < 1000; ++i)
    {
        int special = pow(i, 6);

        if (a <= special && special <= b)
        {
            ++counter;
        }
    }

    cout << counter << endl;
}
