#include <bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int wild;
string A, B;
map<char, int> freq;
vector<char> alphabet;

void init()
{
    for (char c = 'a'; c <= 'z'; ++c)
    {
        alphabet.push_back(c);
    }
}

int main()
{
    init();

    cin >> A >> B;
    int aLength = A.length();
    int bLength = B.length();

    for (int i = 0; i < aLength; ++i)
    {
        char aChar = A[i];
        freq[aChar]++;
    }

    for (int i = 0; i < bLength; ++i)
    {
        char bChar = B[i];
        if (bChar == '*') wild++;
        else freq[bChar]--;
    }

    for (int i = 0; i < alphabet.size(); ++i)
    {
        char alpha = alphabet[i];
        if (freq[alpha] > 0) wild -= freq[alpha];

        if (freq[alpha] < 0)
        {
            cout << "N" << endl;
            return 0;
        }
    }

    if (wild)
    {
        cout << "N" << endl;
    }
    else
    {
        cout << "A" << endl;
    }
}
