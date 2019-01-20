#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < n; ++i)
#define pb push_back
#define endl "\n"

using namespace std;

int main()
{
    int current;
    cin >> current;

    char op; int value;
    while (true)
    {
        cin >> op;
        if (op == '=') break;

        cin >> value;

        if (op == 'M')
        {
            current -= value;
        }
        else if (op == 'P')
        {
            current += value;
        }
    }

    cout << current << endl;
}
