#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
const int SIZE = 27;

map<char, vector<char>> cycle;
map<char, char> encrypt;
vector<char> chars
{
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
    'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
    'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '_'
};
string line, ans = "";
int N;

int main()
{
    char c;
    for (int i = 0; i < SIZE; ++i)
    {
        cin >> c;
        encrypt[chars[i]] = c;
    }

    for (char cha : chars)
    {
        char current = encrypt[cha];
        cycle[cha].push_back(current);

        while (current != cha)
        {
            current = encrypt[current];
            cycle[cha].push_back(current);
        }
    }

    cin >> N >> line;
    for (char c : line)
    {
        int jump = (N - 1) % cycle[c].size();
        ans += cycle[c][jump];
    }

    cout << ans << endl;
}