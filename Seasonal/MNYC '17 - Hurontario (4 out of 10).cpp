#include <bits/stdc++.h>
#define endl "\n"
#define INF 3x3f3f3f3f
#define MOD 1000000007

using namespace std;
hash<string> hasher;
string A, B;

int main()
{
    cin >> A >> B;
    int aLength = A.length();
    int bLength = B.length();
    int length = min(aLength, bLength);

    int best = 0;
    for (int i = 1; i <= length; ++i)
    {
        if (hasher(A.substr(aLength - i, i)) == hasher(B.substr(0, i)))
        {
            best = i;
        }
    }

    string ans = A + B.substr(best, bLength - best);
    cout << ans << endl;
}