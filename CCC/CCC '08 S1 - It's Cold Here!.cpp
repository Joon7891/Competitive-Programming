#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main()
{
    string best; int worst = 200;

    string name; int temp;
    while (true)
    {
        cin >> name >> temp;

        if (temp < worst)
        {
            worst = temp;
            best = name;
        }

        if (name == "Waterloo")
        {
            break;
        }
    }

    cout << best << endl;
}
