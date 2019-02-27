#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
const int MAXN = 155;

int N, M;
int chosen[MAXN];
vector<int> grass[MAXN];
pair<int, int> cows[MAXN];

int main()
{
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);

    cin >> N >> M;

    int a, b;
    for (int i = 0; i < M; ++i)
    {
        cin >> a >> b; a--; b--;
        grass[a].push_back(i);
        grass[b].push_back(i);
        cows[i] = {a, b};
    }

    chosen[0] = 1;
    for (int i = 1; i < N; ++i)
    {
        set<int> disallowed;

        for (int j = 0; j < grass[i].size(); ++j)
        {
            pair<int, int> cow = cows[grass[i][j]];
            if (cow.first < i) disallowed.insert(chosen[cow.first]);
            if (cow.second < i) disallowed.insert(chosen[cow.second]);
        }

        for (int j = 1; j <= 4; ++j)
        {
            if (find(disallowed.begin(), disallowed.end(), j) == disallowed.end())
            {
                chosen[i] = j;
                break;
            }
        }
    }

    for (int i = 0; i < N; ++i)
    {
        cout << chosen[i];
    }
    cout << endl;
}
