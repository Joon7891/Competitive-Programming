#include <bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

unordered_set<char> lower;
string A, B, C;
int N;

void init()
{
    lower.insert('a');
    lower.insert('b');
    lower.insert('c');
    lower.insert('d');
    lower.insert('e');
}

bool solve(string dna)
{
    for (int i = 0; i < 5; ++i)
    {
        char a = dna[i];
        if (find(lower.begin(), lower.end(), a) != lower.end())
        {
            if (find(lower.begin(), lower.end(), A[2 * i + 1]) != lower.end() &&
                find(lower.begin(), lower.end(), B[2 * i + 1]) != lower.end())
            {
                continue;
            }

            return false;
        }
        else
        {
            if (find(lower.begin(), lower.end(), A[2 * i]) == lower.end() ||
                find(lower.begin(), lower.end(), B[2 * i]) == lower.end())
            {
                continue;
            }

            return false;
        }
    }

    return true;
}

int main()
{
    init();

    cin >> A >> B;
    cin >> N;

    while (N--)
    {
        cin >> C;
        if (solve(C))
        {
            cout << "Possible baby." << endl;
        }
        else
        {
            cout << "Not their baby!" << endl;
        }
    }
}
