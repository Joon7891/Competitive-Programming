#include <bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;
vector<int> aFactors;
map<int, int> counter;
map<int, int> totalCounter;

int main()
{
    int a, b;
    cin >> a >> b;

    int i = 2;
    while (a > 1){
        if (a % i == 0){
            aFactors.push_back(i);

            while (a % i == 0){
                counter[i]++;
                a /= i;
            }
        }

        i++;
    }

    for (int i = 2; i <= b; i++){
        int cur = i;
        for (int factor : aFactors){
            while (cur % factor == 0){
                totalCounter[factor]++;
                cur /= factor;
            }
        }
    }

    int best = INF;
    for (int factor : aFactors){
        int pos = totalCounter[factor] / counter[factor];
        best = min(best, pos);
    }

    cout << best << endl;
}