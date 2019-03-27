#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
int N;

int main()
{
    cin >> N;

    int x;
    while (N--)
    {
        cin >> x;

        vector<int> ans;
        if (!x) ans.push_back(0);
        while (x)
        {
            ans.push_back(x & 1);
            x >>= 1;
        }

        while (ans.size() % 4 != 0) ans.push_back(0);

        reverse(ans.begin(), ans.end());

        for (int i = 0; i < ans.size(); ++i)
        {
            cout << ans[i];

            if ((i + 1) % 4 == 0) cout << " ";
        }
        cout << endl;
    }
}
