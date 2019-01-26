#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

const int MAXN = 10000;
string names[MAXN];
int values[MAXN];

int main()
{
    int n; cin >> n;

    string name; int r, s, d, value;
    for (int i = 0; i < n; ++i)
    {
        cin >> name >> r >> s >> d;
        value = 2 * r + 3 * s + d;
        names[i] = name;
        values[i] = value;
    }

    string best1, best2;
    int value1 = -1, value2 = -1;

    for (int i = 0; i < n; ++i)
    {
        if (values[i] > value1 || (names[i] < best1 && values[i] == value1))
        {
            value2 = value1;
            best2 = best1;
            value1 = values[i];
            best1 = names[i];
        }
        else if (values[i] > value2 || (values[i] == value2 && names[i] < best2))
        {
            value2 = values[i];
            best2 = names[i];
        }
    }

    if (value1 != -1)
    {
        cout << best1 << endl;
    }

    if (value2 != -1)
    {
        cout << best2 << endl;
    }
}