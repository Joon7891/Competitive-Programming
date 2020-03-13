#include <bits/stdc++.h>

using namespace std;

bool solve()
{
    string line;
    stack<char> s;

    cin >> line;
    for (char c : line) {
        switch (c)
        {
        case '(':
           s.push(c);

            break;

        case ')':
            if (!s.empty() && s.top() == '(') {
                s.pop();
            } else {
                return false;
            }

            break;

        case '{':
            s.push(c);

            break;

        case '}':
            if (!s.empty() && s.top() == '{') {
                s.pop();
            } else {
                return false;
            }

            break;

        case '[':
            s.push(c);

            break;

        case ']':
            if (!s.empty() && s.top() == '[') {
                s.pop();
            } else {
                return false;
            }

            break;

        default:
            continue;
        }
    }

    return s.empty();
}

int main()
{
    int T = 5;
    while (T--){
        if (solve()) {
            cout << "balanced" << endl;
        } else {
            cout << "not balanced" << endl;
        }
    }
}
