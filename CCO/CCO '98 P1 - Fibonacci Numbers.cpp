#include <bits/stdc++.h>

using namespace std;

map<int, string> fib;
int N;

string add(string a, string b)
{
    if (a.length() < b.length())
    {
        swap(a, b);
    }

    int dif = a.length() - b.length();

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    for (int i = 0; i < dif; ++i) b += "0";

    int carry = 0;
    string ans = "";
    int n = a.length();
    for (int i = 0; i < n; ++i)
    {
        int result = (a[i]-'0') + (b[i]-'0') + carry;
        int first = result % 10;
        carry = result / 10;
        ans += to_string(first);
    }

    if (carry != 0) ans += to_string(carry);

    reverse(ans.begin(), ans.end());
    return ans;
}

string solve(int n)
{
    if (n == 1 || n == 2)
    {
        return "1";
    }

    if (fib.find(n) != fib.end())
    {
        return fib[n];
    }

    return fib[n] = add(solve(n - 1), solve(n - 2));
}

int main()
{
    cin >> N;

    while (N)
    {
        cout << solve(N) << endl;
        cin >> N;
    }
}
