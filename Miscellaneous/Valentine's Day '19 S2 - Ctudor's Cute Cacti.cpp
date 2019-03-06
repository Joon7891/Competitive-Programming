#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

const int MAXN = 100005;
unordered_map<int, bool> row;
unordered_map<int, bool> column;
unordered_map<int, unordered_map<int, bool> > individual;
int N, Q;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> Q;

    while (Q--)
    {
        int a, i, j;
        cin >> a >> i >> j;

        if (a == 1)
        {
            individual[i][j] = !individual[i][j];
            row[i] = !row[i];
            column[j] = !column[j];
        }
        else
        {
            int state = individual[i][j] + row[i] + column[j];
            state = (state ) % 2;

            cout << state << endl;
        }
    }