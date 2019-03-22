#include <bits/stdc++.h>
#define MEM(a, b) memset(a, b, sizeof(a))

using namespace std;
int a[1001];

void solve()
{
    int n, m, d;
    cin>> n >> m >> d;

    MEM(a,0);
    int n2 = n, c=0;
    for(int i = 0, x; i < m; i++)
    {
        cin>>x;
        a[x]++;
    }

    for(int i = 1; i <= d; i++)
    {
        if(n == 0) 
        {
            n=n2;
            c++;
        }

        n--;
        n += a[i];
        n2 += a[i];

    }
    cout << c << endl;
}

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);

    for(int i = 0; i < 10; i++)
    {
        solve();
    }
}