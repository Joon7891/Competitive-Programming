#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
int N, M;

int main()
{
    cin >> N >> M;
    
    if (N >= M - 1)
    {
        cout << M - 1 << endl;
    }
    else
    {
        cout << N << endl;
    }
}