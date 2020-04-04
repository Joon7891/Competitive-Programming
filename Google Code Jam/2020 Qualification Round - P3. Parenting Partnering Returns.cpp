#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MOD 1000000007

using namespace std;

void solve(int index){
    int N; cin >> N;
    vector<tuple<int, int, int>> tasks;

    for (int i = 0, beg, fin; i < N; i++){
        cin >> beg >> fin;
        tasks.push_back(make_tuple(beg, fin, i));
    }

    sort(tasks.begin(), tasks.end());

    vector<pair<int, char>> order;
    int camCur = 0;
    int jamieCur = 0;
    for (int i = 0; i < N; i++){
        int beg = get<0>(tasks[i]);
        int fin = get<1>(tasks[i]);
        int ind = get<2>(tasks[i]);

        if (beg >= camCur){
            camCur = fin;
            order.push_back({ind, 'C'});
        }
        else if (beg >= jamieCur){
            jamieCur = fin;
            order.push_back({ind, 'J'});
        }
        else {
            cout << "Case #" << index << ": IMPOSSIBLE" << endl;
            return;
        }
    }

    string ans = "";
    sort(order.begin(), order.end());
    for (int i = 0; i < N; i++){
        ans += order[i].second;
    }

    cout << "Case #" << index << ": " << ans << endl;
}

int main(){
    int T; cin >> T;
    for (int i = 1; i <= T; i++) solve(i);
}