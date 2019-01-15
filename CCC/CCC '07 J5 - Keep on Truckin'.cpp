#include <bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define pb push_back
#define f first
#define s second
#define MEM(a, b) memset(a, b, sizeof(a))
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;
typedef long long ll;

const int MAXN = 40;
vector<int> hotels;
ll counter[40];

void init()
{
    hotels.pb(0);
    hotels.pb(990);
    hotels.pb(1010);
    hotels.pb(1970);
    hotels.pb(2030);
    hotels.pb(2940);
    hotels.pb(3060);
    hotels.pb(3930);
    hotels.pb(4060);
    hotels.pb(4970);
    hotels.pb(5030);
    hotels.pb(5990);
    hotels.pb(6010);
    hotels.pb(7000);
}

int main()
{
    MEM(counter, 0);
    init();

    int a, b;
    cin >> a >> b;

    int m, d;
    cin >> m;
    forn(i, m)
    {
        cin >> d;
        hotels.pb(d);
    }

    sort(hotels.begin(), hotels.end());

    counter[0] = 1;

    forn(i, hotels.size())
    {
        ll current = hotels[i];

        forn(j, hotels.size())
        {
            if (i != j && current + a <= hotels[j] && hotels[j] <= current + b)
            {
                counter[j] += counter[i];
            }
        }
    }

    cout << counter[hotels.size() - 1] << endl;
}