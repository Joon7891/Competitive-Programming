#include <bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;
const int MAXN = 1000005;

int J, A;
char sizer[MAXN];
vector<pair<int, char> > requests;

int main()
{
    cin >> J >> A;

    for (int i = 0; i < J; ++i)
    {
        cin >> sizer[i + 1];
    }

    char newSize; int num;
    for (int i = 0; i < A; ++i)
    {
        cin >> newSize >> num;
        requests.push_back({num, newSize});
    }

    sort(requests.begin(), requests.end());
    reverse(requests.begin(), requests.end());

    int total = 0;
    for (int i = 0; i < A; ++i)
    {
        int number = requests[i].first;
        char letter = requests[i].second;

        if (sizer[number] <= letter)
        {
            total++;
            sizer[number] = 'Z';
        }
    }

    cout << total << endl;
    return 0;
}
