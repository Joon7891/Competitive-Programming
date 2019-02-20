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
    alphabet.push_back('a');
    alphabet.push_back('b');
    alphabet.push_back('c');
    alphabet.push_back('d');
    alphabet.push_back('e');
    alphabet.push_back('f');
    alphabet.push_back('g');
    alphabet.push_back('h');
    alphabet.push_back('i');
    alphabet.push_back('j');
    alphabet.push_back('k');
    alphabet.push_back('l');
    alphabet.push_back('m');
    alphabet.push_back('n');
    alphabet.push_back('o');
    alphabet.push_back('p');
    alphabet.push_back('q');
    alphabet.push_back('r');
    alphabet.push_back('s');
    alphabet.push_back('t');
    alphabet.push_back('u');
    alphabet.push_back('v');
    alphabet.push_back('w');
    alphabet.push_back('x');
    alphabet.push_back('y');
    alphabet.push_back('z');
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
