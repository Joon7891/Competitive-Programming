#include <bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;
const int MAXN = 1000005;

unordered_map<char, int> toInt;
vector<char> alphabet;
int psa[27][MAXN];
string A;

void init()
{
    for (int i = 0; i < 26; ++i)
    {
        toInt['a' + i] = i;
    }
    toInt[' '] = 26;
}

int main()
{
    init();
    getline(cin, A);

    int length = A.length();
    for (int i = 1; i <= length; ++i)
    {
        psa[toInt[A[i - 1]]][i]++;

        for (int j = 0; j < 26; ++j)
        {
            psa[j][i] += psa[j][i - 1];
        }
    }

    int Q; cin >> Q;
    int a, b; char c;
    while (Q--)
    {
        cin >> a >> b >> c;
        cout << psa[toInt[c]][b] - psa[toInt[c]][a - 1] << endl;
    }
}