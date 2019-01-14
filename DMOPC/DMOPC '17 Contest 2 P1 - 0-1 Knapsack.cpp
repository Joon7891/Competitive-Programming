#include <iostream>

using namespace std;

const int MAXN = 100000;
int c[MAXN];
int v[MAXN];

int main() {
    int n;
    cin >> n;

    long long size = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> c[i] >> v[i];

        if (v[i] > 0)
        {
            size += c[i];
        }
    }

    cout << size << "\n";
}
