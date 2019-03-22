#include <bits/stdc++.h>
#define MEM(a, b) memset(a, b, sizeof(a))

using namespace std;

void solve(){
    char a[105][13];
    MEM(a,'@');

    int j, w, h;
    cin>> j >> w >> h;

    string s;
    int x = 0,y = h - 2;

    for(int i = 0; i < h; i++)
    {
        cin >> s;
        for(int j = 0; j < w; j++)
        {
            a[j][i] = s[j];
            if(s[j] == 'L')
            {
                x = j;
            }
        }
    }

    while(1)
    {
        if(a[x][y] == 'G'){
            cout << "CLEAR" << endl;
            return;
        }
        else if (a[x + 1][y] == '.'|| a[x + 1][y] == 'G')
        {
            x++;
        }
        else if(a[x + 1][y] != '.')
        {
            bool c = 0;
            for(int i = 1; i <= j; i++)
            {
                if(y - i < 0) continue;
                if(x + 2 >= w) continue;

                bool l = 1;
                for(int k = h - 1; k >= y - i; k--)
                {
                    if(a[x][k] == '@') l = 0;
                }

                if(!l) continue;

                bool n=1;

                for(int k = h-1; k >= y-i; k--)
                {
                    if(a[x + 2][k] == '@') n = 0;
                }

                if(n==0) continue;
                if(a[x][y - i] != '.') continue;

                if(y - i < 0)
                {
                    if(a[x + 2][y - i] == '.')
                    {
                        x = x + 2;
                        y = y - i;
                        c = 1;
                        break;
                    }
                }

                if (a[x + 1][y - i] == '.')
                {
                    c = 1;
                    x = x+2;
                    break;
                }
            }

            if(!c)
            {
                cout << x+2 << endl;
                return;
            }
        }

    }
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
