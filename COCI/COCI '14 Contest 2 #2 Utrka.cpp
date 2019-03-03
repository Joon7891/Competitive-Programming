#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

map<int, string> hash_to_str;
hash<string> str_hash;
int hash_total = 0;
int N;

int main()
{
    cin >> N;

    string c; int hashed;
    for (int i = 0; i < N; ++i)
    {
        cin >> c;
        hashed = str_hash(c);
        hash_total ^= hashed;
        hash_to_str[hashed] = c;
    }

    for (int i = 0; i < N - 1; ++i)
    {
        cin >> c;
        hash_total ^= str_hash(c);
    }

    cout << hash_to_str[hash_total] << endl;
}
