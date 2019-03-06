#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10000;
int intervals[MAXN];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, d; cin >> n >> d;
    
    for (int i = 0; i < n; ++i)
    {
        cin >> intervals[i];
    }

    sort(intervals, intervals + n);

    for (int i = n - 1; i >= 0; --i)
    {
        if (d % intervals[i] == 0)
        {
            cout << abs(d / intervals[i]) << "\n";
            break;
        }

        if (i == 0)
        {
            cout << "This is not the best time for a trip." << "\n";
        }
    }    
}
