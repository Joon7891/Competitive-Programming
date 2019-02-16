#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;
char digits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
map<char, int> numbers;
string a, b;

void init()
{
    numbers['0'] = 0;
    numbers['1'] = 1;
    numbers['2'] = 2;
    numbers['3'] = 3;
    numbers['4'] = 4;
    numbers['5'] = 5;
    numbers['6'] = 6;
    numbers['7'] = 7;
    numbers['8'] = 8;
    numbers['9'] = 9;
}

string add()
{
    if (a.length() < b.length())
    {
        swap(a, b);
    }

    int dif = a.length() - b.length();

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    for (int i = 0; i < dif; ++i)
    {
        b += "0";
    }

    string ans = "";

    int n = a.length();
    int carry = 0;
    for (int i = 0; i < n; ++i)
    {
        int result = numbers[a[i]] + numbers[b[i]] + carry;
        carry = 0;
        int first = result % 10;
        carry = result / 10;
        ans += digits[first];
    }

    if (carry != 0) ans += digits[carry];

    reverse(ans.begin(), ans.end());
    return ans;
}

bool bigger(string n1, string n2)
{
    if(n1.length() == n2.length())
    {
        int n = n1.length();
        for (int i = 0; i < n; ++i)
        {
            int num1 = numbers[n1[i]];
            int num2 = numbers[n2[i]];

            if (num1 == num2) continue;
            return num1 > num2;
        }

        return true;
    }

    return n1.length() > n2.length();
}

string dif()
{
    if (!bigger(a, b))
    {
        swap(a, b);
    }

    string ans = "";
    int dif = a.length() - b.length();

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    for (int i = 0; i < dif; ++i)
    {
        b += "0";
    }

    int n = a.length();
    int carry = 0;
    for (int i = 0; i < n; ++i)
    {
        int a_num = numbers[a[i]];
        int b_num = numbers[b[i]];
        int result = a_num - b_num - carry;
        carry = 0;

        if (result >= 0)
        {
            ans += digits[result];
        }
        else
        {
            carry = 1;
            ans += digits[result + 10];
        }
    }

    reverse(ans.begin(), ans.end());

    int pivot = 0;
    for (int i = 0; i < n; ++i)
    {
        if (ans[i] == '0')
        {
            pivot = i + 1;
        }
        else
        {
            break;
        }
    }

    ans = ans.substr(pivot);

    return ans;
}

string solve()
{
    bool a_neg = a[0] == '-';
    bool b_neg = b[0] == '-';

    if (a_neg) a = a.substr(1);
    if (b_neg) b = b.substr(1);

    if (a_neg != b_neg)
    {
        bool a_bigger = bigger(a, b);
        string ans = dif();

        if ((a_neg && a_bigger) || (b_neg && !a_bigger))
        {
            return "-" + ans;
        }
        else
        {
            return ans;
        }
    }
    else
    {
        if (a_neg && b_neg)
        {
            return "-" + add();
        }
        else
        {
            return add();
        }
    }
}

int main()
{
    init();
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int m; cin >> m;

    while (m--)
    {
        cin >> a >> b;
        string ans = solve();
        if (ans == "-" || ans == "")
        {
            ans = "0";
        }

        cout << ans << endl;
    }
}
