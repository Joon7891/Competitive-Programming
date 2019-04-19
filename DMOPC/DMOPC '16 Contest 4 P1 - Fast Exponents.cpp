#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
int N;

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0); cout.tie(0);

    cin >> N;

    unsigned long long x;
    while (N--)
    {
        cin >> x;

        if (x & (x - 1))
        {
            cout << "F" << endl;
        }
        else
        {
            cout << "T" << endl;
        }
    }
}