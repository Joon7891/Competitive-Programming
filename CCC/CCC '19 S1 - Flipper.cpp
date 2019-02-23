#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
string A;
int length;
int hCount = 0;
int vCount = 0;

int main()
{
    cin >> A;
    length = A.length();

    for (int i = 0; i < length; ++i)
    {
        if (A[i] == 'H')
        {
            hCount++;
        }
        else
        {
            vCount++;
        }
    }

    if (vCount % 2 == 0)
    {
        if (hCount % 2 == 0)
        {
            cout << 1 << " " << 2 << endl;
            cout << 3 << " " << 4 << endl;
        }
        else
        {
            cout << 3 << " " << 4 << endl;
            cout << 1 << " " << 2 << endl;
        }
    }
    else
    {
        if (hCount % 2 == 0)
        {
            cout << 2 << " " << 1 << endl;
            cout << 4 << " " << 3 << endl;
        }
        else
        {
            cout << 4 << " " << 3 << endl;
            cout << 2 << " " << 1 << endl;
        }
    }
}