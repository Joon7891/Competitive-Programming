#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;

    int year, month, day;
    while (n--)
    {
        cin >> year >> month >> day;

        if (2007 - year > 18 || (2007 - year == 18 && (month < 2 || (month == 2 && day <= 27))))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}