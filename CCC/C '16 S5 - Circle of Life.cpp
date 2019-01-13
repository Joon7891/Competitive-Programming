#include <bits/stdc++.h>

using namespace std;

bool *currentGame;
bool *newGame;
long long n, t;

long long getPow(long long a)
{
    unsigned long long answer = 1;

    // 64 as it is the max bits of a long long
    for (int i = 0; i < 64; ++i)
    {
        answer <<= 1;

        if(answer > a)
        {
            answer >>= 1;
            return (long long)answer;
        }
    }

    return (long long) answer;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> t;
    string input; cin >> input;
    currentGame = new bool[n];
    newGame = new bool[n];
    for (int i = 0; i < n; ++i) currentGame[i] = input[i] == '1';

    long long powJump;
    long long index1, index2;
    while (t > 0)
    {
        powJump = getPow(t);

        for (int i = 0; i < n; ++i)
        {
            index1 = (i - powJump % n + n) % n;
            index2 = (i + powJump % n) % n;
            newGame[i] = currentGame[index1] ^ currentGame[index2];
        }

        currentGame = newGame;
        newGame = new bool[n];
        t -= powJump;
    }

    for (int i = 0; i < n; ++i) cout << currentGame[i];
    cout << "\n";
}