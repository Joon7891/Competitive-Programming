#include <bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;
const int MAXN = 200005;

int a[MAXN];
int b[MAXN];

map<pair<int, int>, int> counter;
set<pair<int, int>> keySet;
vector<pair<int, int>> keys;
int globalCount = 0;

int main(){
    int N; cin >> N;

    for (int i = 0; i < N; i++) cin >> a[i];
    for (int i = 0; i < N; i++) cin >> b[i];

    for (int i = 0; i < N; i++){
        if (b[i] == 0 && a[i] == 0) globalCount++;
        else if (a[i] == 0) continue;
        else {
            int gcd = __gcd(a[i], b[i]);
            a[i] /= gcd;
            b[i] /= gcd;

            if (b[i] < 0){
                a[i] *= -1;
                b[i] *= -1;
            }

            counter[{a[i], b[i]}]++;
            if (keySet.find({a[i], b[i]}) == keySet.end()){
                keySet.insert({a[i], b[i]});
                keys.push_back({a[i], b[i]});
            }
        }
    }

    int best = 0;
    for (pair<int, int> pii : keys){
        if (counter[pii] > best) best = counter[pii];
    }

    cout << best + globalCount << endl;
}