#include <bits/stdc++.h>

using namespace std;
int t, g;

int solve(list<pair<int, int> > gamesLeft, int leaderboard[4])
{
    if (gamesLeft.size() == 0)
    {
        int score = max(max(leaderboard[0], leaderboard[1]), max(leaderboard[2], leaderboard[3]));
        if (leaderboard[t] == score)
        {
            // Should start reading question more carefully :/
            int counter = 0;
            for (int i = 0; i < 4; ++i)
            {
                if (leaderboard[i] == score)
                {
                    ++counter;
                }
            }

            if (counter == 1)
            {
                return 1;
            }

            return 0;
        }
        else
        {
            return 0;
        }
    }

    pair<int, int> currentGame = gamesLeft.front();
    int a = currentGame.first, b = currentGame.second;
    gamesLeft.pop_front();

    int tieLeaderboard[4];
    tieLeaderboard[0] = leaderboard[0];
    tieLeaderboard[1] = leaderboard[1];
    tieLeaderboard[2] = leaderboard[2];
    tieLeaderboard[3] = leaderboard[3];

    tieLeaderboard[a] += 1;
    tieLeaderboard[b] += 1;
    int tie = solve(gamesLeft, tieLeaderboard);

    int winLeaderboard[4];
    winLeaderboard[0] = leaderboard[0];
    winLeaderboard[1] = leaderboard[1];
    winLeaderboard[2] = leaderboard[2];
    winLeaderboard[3] = leaderboard[3];
    winLeaderboard[a] += 3;
    int win = solve(gamesLeft, winLeaderboard);

    int lossLeaderboard[4];
    lossLeaderboard[0] = leaderboard[0];
    lossLeaderboard[1] = leaderboard[1];
    lossLeaderboard[2] = leaderboard[2];
    lossLeaderboard[3] = leaderboard[3];
    lossLeaderboard[b] += 3;
    int loss = solve(gamesLeft, lossLeaderboard);

    return tie + win + loss;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    list<pair<int, int> > gamesLeft;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            gamesLeft.push_back(make_pair(i, j));
        }
    }

    int leaderboard[4];
    leaderboard[0] = 0;
    leaderboard[1] = 0;
    leaderboard[2] = 0;
    leaderboard[3] = 0;

    cin >> t >> g;
    --t;

    int a, b, sa, sb;
    for (int i = 0; i < g; ++i)
    {
        cin >> a >> b >> sa >> sb;
        --a;
        --b;

        gamesLeft.remove(make_pair(a, b));
        gamesLeft.remove(make_pair(b, a));

        if (sa == sb)
        {
            leaderboard[a] += 1;
            leaderboard[b] += 1;
        }
        else if (sa > sb)
        {
            leaderboard[a] += 3;
        }
        else
        {
            leaderboard[b] += 3;
        }
    }
    cout << solve(gamesLeft, leaderboard) << "\n";
}
