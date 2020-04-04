#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MOD 1000000007

using namespace std;

string paren(string input, int tolerance){
    string res = "";

    bool valid = input[0]-'0' >= tolerance;
    int start = valid ? 0 : -1;
    int length = 0;
    for (int i = 0; i < input.length(); i++){
        if (input[i]-'0' < tolerance){
            if (valid){
                res += "(" + paren(input.substr(start, length), tolerance + 1) + ")";
            }

            valid = false;
            res += input[i];
        }
        else {
            if (!valid){
                valid = true;
                start = i;
                length = 1;
            }
            else {
                length++;
            }
        }
    }

    if (valid){
        res += "(" + paren(input.substr(start, length), tolerance + 1) + ")";
    }

    return res;
}

void solve(int index){
    string line; cin >> line;
    string ans = paren(line, 1);
    cout << "Case #" << index << ": " << ans << endl;
}

int main(){
    int T; cin >> T;
    for (int i = 1; i <= T; i++) solve(i);
}