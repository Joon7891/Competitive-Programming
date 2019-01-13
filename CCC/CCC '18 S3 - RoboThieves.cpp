#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < n; ++i)
#define endl "\n"
#define pb push_back

using namespace std;

struct point
{
    int y, x;

    point(int y, int x) : y(y), x(x) {}
};

const int MAX_SIZE = 100;
char grid[MAX_SIZE][MAX_SIZE];
bool camera[MAX_SIZE][MAX_SIZE];
int d[MAX_SIZE][MAX_SIZE];
int n, m;

point get_start()
{
    forn(i, n)
    {
        forn(j, m)
        {
            if (grid[i][j] == 'S')
            {
                return point(i, j);
            }
        }
    }
}

vector<point> get_ends()
{
    vector<point> ends;

    forn(i, n)
    {
        forn(j, m)
        {
            if (grid[i][j] == '.')
            {
                ends.pb(point(i, j));
            }
        }
    }

    return ends;
}

bool in_grid(int y, int x)
{
    return -1 < y && y < n && -1 < x && x < m;
}

void set_cameras()
{
    forn(i, n)
    {
        forn(j, m)
        {
            if (grid[i][j] == 'C')
            {
                camera[i][j] = true;

                for (int ci = i - 1; ci >= 0; --ci)
                {
                    if (grid[ci][j] == 'W')
                    {
                        break;
                    }
                    else
                    {
                        camera[ci][j] = true;
                    }
                }

                for (int ci = i + 1; ci < n; ++ci)
                {
                    if (grid[ci][j] == 'W')
                    {
                        break;
                    }
                    else
                    {
                        camera[ci][j] = true;
                    }
                }

                for (int cj = j - 1; cj >= 0; --cj)
                {
                    if (grid[i][cj] == 'W')
                    {
                        break;
                    }
                    else
                    {
                        camera[i][cj] = true;
                    }
                }

                for (int cj = j + 1; cj < m; ++cj)
                {
                    if (grid[i][cj] == 'W')
                    {
                        break;
                    }
                    else
                    {
                        camera[i][cj] = true;
                    }
                }
            }
        }
    }
}

void bfs(point start)
{
    d[start.y][start.x] = 0;
    queue<point> q;

    if (!camera[start.y][start.x])
    {
        q.push(start);
    }

    while (!q.empty())
    {
        point current = q.front(); q.pop();
        int y = current.y;
        int x = current.x;

        if (grid[y][x] == '.' || grid[y][x] == 'S')
        {
            int newX = x - 1;
            int newY = y;
            if (in_grid(newY, newX) && (d[newY][newX] == -1 || d[newY][newX] > d[y][x] + 1) && grid[newY][newX] != 'W')
            {
                if (grid[newY][newX] == '.')
                {
                    if (!camera[newY][newX])
                    {
                        d[newY][newX] = d[y][x] + 1;
                        q.push(point(newY, newX));
                    }
                }
                else
                {
                    d[newY][newX] = d[y][x] + 1;
                    q.push(point(newY, newX));
                }
            }

            newX = x + 1;
            newY = y;
            if (in_grid(newY, newX) && (d[newY][newX] == -1 || d[newY][newX] > d[y][x] + 1) && grid[newY][newX] != 'W')
            {
                if (grid[newY][newX] == '.')
                {
                    if (!camera[newY][newX])
                    {
                        d[newY][newX] = d[y][x] + 1;
                        q.push(point(newY, newX));
                    }
                }
                else
                {
                    d[newY][newX] = d[y][x] + 1;
                    q.push(point(newY, newX));
                }
            }

            newX = x;
            newY = y - 1;
            if (in_grid(newY, newX) && (d[newY][newX] == -1 || d[newY][newX] > d[y][x] + 1) && grid[newY][newX] != 'W')
            {
                if (grid[newY][newX] == '.')
                {
                    if (!camera[newY][newX])
                    {
                        d[newY][newX] = d[y][x] + 1;
                        q.push(point(newY, newX));
                    }
                }
                else
                {
                    d[newY][newX] = d[y][x] + 1;
                    q.push(point(newY, newX));
                }
            }

            newX = x;
            newY = y + 1;
            if (in_grid(newY, newX) && (d[newY][newX] == -1 || d[newY][newX] > d[y][x] + 1) && grid[newY][newX] != 'W')
            {
                if (grid[newY][newX] == '.')
                {
                    if (!camera[newY][newX])
                    {
                        d[newY][newX] = d[y][x] + 1;
                        q.push(point(newY, newX));
                    }
                }
                else
                {
                    d[newY][newX] = d[y][x] + 1;
                    q.push(point(newY, newX));
                }
            }
        }
        else if (grid[y][x] == 'L')
        {
            if (in_grid(y, x - 1) && (d[y][x - 1] == -1 || d[y][x - 1] > d[y][x]) && grid[y][x - 1] != 'W')
            {
                if (grid[y][x - 1] == '.')
                {
                    if (!camera[y][x - 1])
                    {
                        d[y][x - 1] = d[y][x];
                        q.push(point(y, x - 1));
                    }
                }
                else if (grid[y][x - 1] != 'C')
                {
                    d[y][x - 1] = d[y][x];
                    q.push(point(y, x - 1));
                }
            }
        }
        else if (grid[y][x] == 'R')
        {
            if (in_grid(y, x + 1) && (d[y][x + 1] == -1 || d[y][x + 1] > d[y][x]) && grid[y][x + 1] != 'W')
            {
                if (grid[y][x + 1] == '.')
                {
                    if (!camera[y][x + 1])
                    {
                        d[y][x + 1] = d[y][x];
                        q.push(point(y, x + 1));
                    }
                }
                else if (grid[y][x + 1] != 'C')
                {
                    d[y][x + 1] = d[y][x];
                    q.push(point(y, x + 1));
                }
            }
        }
        else if (grid[y][x] == 'U')
        {
            if (in_grid(y - 1, x) && (d[y - 1][x] == -1 || d[y - 1][x] > d[y][x]) && grid[y - 1][x] != 'W')
            {
                if (grid[y - 1][x] == '.')
                {
                    if (!camera[y - 1][x])
                    {
                        d[y - 1][x] = d[y][x];
                        q.push(point(y - 1, x));
                    }
                }
                else if (grid[y - 1][x] != 'C')
                {
                    d[y - 1][x] = d[y][x];
                    q.push(point(y - 1, x));
                }
            }
        }
        else if (grid[y][x] == 'D')
        {
            if (in_grid(y + 1, x) && (d[y + 1][x] == -1 || d[y + 1][x] > d[y][x]) && grid[y + 1][x] != 'W')
            {
                if (grid[y + 1][x] == '.')
                {
                    if (!camera[y + 1][x])
                    {
                        d[y + 1][x] = d[y][x];
                        q.push(point(y + 1, x));
                    }
                }
                else if (grid[y + 1][x] != 'C')
                {
                    d[y + 1][x] = d[y][x];
                    q.push(point(y + 1, x));
                }
            }
        }
    }
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(d, -1, sizeof(d));
    memset(camera, false, sizeof(camera));

    cin >> n >> m;

    string new_line;
    forn(i, n)
    {
        cin >> new_line;

        forn(j, m)
        {
            grid[i][j] = new_line[j];
        }
    }

    point start = get_start();
    vector<point> endpoints = get_ends();
    set_cameras();

    bfs(start);

    forn(i, endpoints.size())
    {
        cout << d[endpoints[i].y][endpoints[i].x] << endl;
    }
}