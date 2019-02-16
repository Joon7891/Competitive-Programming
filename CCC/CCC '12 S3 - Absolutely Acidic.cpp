#include <bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

const int MAXN = 1005;
int v[MAXN];
int N;

map<int, int> freq;
vector<int> known;
vector<pair<int, int> > sol;

int main()
{
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        int v; cin >> v;

        if (find(known.begin(), known.end(), v) == known.end()) known.push_back(v);

        ++freq[v];
    }

    for (int i = 0; i < known.size(); ++i)
    {
        int value = known[i];
        int total = freq[value];

        sol.push_back({total, value});
    }

    sort(sol.begin(), sol.end());
    reverse(sol.begin(), sol.end());

    if (N == 2)
    {
        cout << abs(sol[0].second - sol[1].second) << endl;
        return 0;
    }

    if (sol[0].first != sol[1].first && sol[1].first != sol[2].first)
    {
        cout << abs(sol[0].second - sol[1].second) << endl;
        return 0;
    }

    if (sol[0].first == sol[1].first)
    {
        int min_value = sol[0].second;
        int max_value = sol[0].second;

        for (int i = 1; i < sol.size(); ++i)
        {
            if (sol[i].first != sol[0].first) break;

            min_value = min(min_value, sol[i].second);
            max_value = max(max_value, sol[i].second);
        }

        cout << max_value - min_value << endl;
        return 0;
    }

    if (sol[1].first == sol[2].first)
    {
        int min_value = sol[1].second;
        int max_value = sol[1].second;

        for (int i = 2; i < sol.size(); ++i)
        {
            if (sol[i].first != sol[1].first) break;

            min_value = min(min_value, sol[i].second);
            max_value = max(max_value, sol[i].second);
        }

        int d1 = abs(sol[0].second - min_value);
        int d2 = abs(sol[0].second - max_value);
        int d = max(d1, d2);
        cout << d << endl;
        return 0;
    }
}