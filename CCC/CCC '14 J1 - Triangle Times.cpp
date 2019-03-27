#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
int a, b, c, t;

int main()
{
    cin >> a >> b >> c;
    t = a + b + c;

    if (t ^ 180)
    {
        cout << "Error" << endl;
    }
    else
    {
        if (a == b && b == c)
        {
            cout << "Equilateral" << endl;
        }
        else if (a ^ b && b ^ c && a ^ c)
        {
            cout << "Scalene" << endl;
        }
        else
        {
            cout << "Isosceles" << endl;
        }
    }
}
