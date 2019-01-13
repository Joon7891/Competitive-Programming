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

const int MAXN = 30;
int n;
string a[MAXN];
string b[MAXN];
map<string, string> mapper;

bool valid()
{
    forn(i, n)
    {
        string current = a[i];
        if (a[i] != b[i] && mapper[a[i]] == b[i] && mapper[b[i]] == a[i])
        {
            continue;
        }
        else
        {
            return false;
        }
    }

    return true;
}

int main()
{
    cin >> n;

    forn(i, n) cin >> a[i];
    forn(i, n) cin >> b[i];
    forn(i, n)
    {
        if (mapper.find(a[i]) == mapper.end()) mapper[a[i]] = b[i];
        else
        {
            cout << "bad" << endl;
            return 0;
        }
    }

    if (valid())
    {
        cout << "good" << endl;
    }
    else
    {
        cout << "bad" << endl;
    }
}