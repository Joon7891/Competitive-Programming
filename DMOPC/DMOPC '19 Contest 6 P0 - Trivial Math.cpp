#include <bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    if (a + b > c && b + c > a && a + c > b){
        cout << "yes" << endl;
    }
    else {
        cout << "no" << endl;
    }
}