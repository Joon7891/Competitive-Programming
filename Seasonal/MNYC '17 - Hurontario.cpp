#include <bits/stdc++.h>
#define endl "\n"
#define INF 3x3f3f3f3f
#define MOD 1000000007
#define P 89

using namespace std;
typedef long long ll;

unordered_map<char, int> charToNum;
int aLength, bLength, length;
string A, B;

void init()
{
    charToNum['A'] = 1;
    charToNum['B'] = 2;
    charToNum['C'] = 3;
    charToNum['D'] = 4;
    charToNum['E'] = 5;
    charToNum['F'] = 6;
    charToNum['G'] = 7;
    charToNum['H'] = 8;
    charToNum['I'] = 9;
    charToNum['J'] = 10;
    charToNum['K'] = 11;
    charToNum['L'] = 12;
    charToNum['M'] = 13;
    charToNum['N'] = 14;
    charToNum['O'] = 15;
    charToNum['P'] = 16;
    charToNum['Q'] = 17;
    charToNum['R'] = 18;
    charToNum['S'] = 19;
    charToNum['T'] = 20;
    charToNum['U'] = 21;
    charToNum['V'] = 22;
    charToNum['W'] = 23;
    charToNum['X'] = 24;
    charToNum['Y'] = 25;
    charToNum['Z'] = 26;
}

string solve()
{
    int best = 0;
    ll aHash = 0;
    ll bHash = 0;
    ll bPow = 1;

    for (int i = 0; i < length; ++i)
    {
        char aChar = A[aLength - i - 1];
        char bChar = B[i];
        aHash = (P * aHash + charToNum[aChar]) % MOD;
        bHash = (bHash + charToNum[bChar] * bPow) % MOD;
        bPow = (bPow * P) % MOD;

        if (aHash == bHash) best = i + 1;
    }

    return A + B.substr(best, bLength - best);
}

int main()
{
    init();

    cin >> A >> B;
    aLength = A.length();
    bLength = B.length();
    length = min(aLength, bLength);

    cout << solve() << endl;
}
