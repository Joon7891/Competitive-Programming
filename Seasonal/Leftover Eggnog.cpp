#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < n; ++i)
#define endl "\n"
#define MEM(a, b) memset(a, (b), sizeof(a))
#define INF 0x3f3f3f3f

using namespace std;

struct state
{
    int a, b;

    state(int a, int b) : a(a), b(b) {}
};

const int MAX = 1000;
bool visited[MAX + 1][MAX + 1];
string currentMove[MAX + 1][MAX + 1];
pair<int, int> previousState[MAX + 1][MAX + 1];
int a_win, b_win;
int va, vb, m;
bool solution = false;

bool valid(int a, int b)
{
    return !visited[a][b];
}

void solve()
{
    queue<state> q;
    visited[0][0] = true;
    q.push(state(0, 0));

    while (!q.empty())
    {
        state current = q.front(); q.pop();
        int a = current.a;
        int b = current.b;

        //cout << currentMove[a][b] << " " << a << " " << b << endl;

        // Fill A
        if (valid(va, b))
        {
            visited[va][b] = true;
            previousState[va][b] = {a, b};
            currentMove[va][b] = "fill A";
            q.push(state(va, b));
        }

        // Fill B
        if (valid(a, vb))
        {
            visited[a][vb] = true;
            previousState[a][vb] = {a, b};
            currentMove[a][vb] = "fill B";
            q.push(state(a, vb));
        }

        // Chug A
        if (valid(0, b))
        {
            visited[0][b] = true;
            previousState[0][b] = {a, b};
            currentMove[0][b] = "chug A";
            q.push(state(0, b));
        }

        // Chug B
        if (valid(a, 0))
        {
            visited[a][0] = true;
            previousState[a][0] = {a, b};
            currentMove[a][0] = "chug B";
            q.push(state(a, 0));
        }

        // Pour A into B
        int space = vb - b;
        int delta = min(space, a);
        int newA = a - delta;
        int newB = b + delta;
        if (valid(newA, newB))
        {
            visited[newA][newB] = true;
            previousState[newA][newB] = {a, b};
            currentMove[newA][newB] = "pour A B";
            q.push(state(newA, newB));
        }

        // Pour B into A
        space = va - a;
        delta = min(space, b);
        newA = a + delta;
        newB = b - delta;
        if (valid(newA, newB))
        {
            visited[newA][newB] = true;
            previousState[newA][newB] = {a, b};
            currentMove[newA][newB] = "pour B A";
            q.push(state(newA, newB));
        }

        if (a == m || b == m)
        {
            a_win = a;
            b_win = b;
            solution = true;
            return;
        }
    }

    solution = false;
}

void output()
{
    vector<string> moves;

    int currentA = a_win;
    int currentB = b_win;
    while (true)
    {
        moves.push_back(currentMove[currentA][currentB]);
        pair<int, int> prev = previousState[currentA][currentB];
        currentA = prev.first;
        currentB = prev.second;

        if (currentA == 0 && currentB == 0)
        {
            break;
        }
    }

    reverse(moves.begin(), moves.end());
    forn(i, moves.size())
    {
        cout << moves[i] << endl;
    }
}

int main()
{
    MEM(visited, false);

    cin >> va >> vb >> m;
    solve();

    if (!solution)
    {
        cout << "Not possible" << endl;
    }
    else
    {
        output();
    }
}