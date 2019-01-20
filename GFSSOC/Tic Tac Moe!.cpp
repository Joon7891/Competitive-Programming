#include <bits/stdc++.h>

using namespace std;
char grid[3][3];

bool win(char player)
{
    for (int i = 0; i < 3; ++i)
    {
        if (grid[i][0] == player && grid[i][1] == player && grid[i][2] == player)
        {
            return true;
        }

        if (grid[0][i] == player && grid[1][i] == player && grid[2][i] == player)
        {
            return true;
        }
    }

    if (grid[0][0] == player && grid[1][1] == player && grid[2][2] == player)
    {
        return true;
    }

    if (grid[2][0] == player && grid[1][1] == player && grid[0][2] == player)
    {
        return true;
    }

    return false;
}

int main()
{
    string buffer;

    for (int i = 0; i < 3; ++i)
    {
        cin >> buffer;

        for (int j = 0; j < 3; ++j)
        {
            grid[i][j] = buffer[j];
        }
    }

    bool oWin = win('O');
    bool xWin = win('X');

    if (oWin && !xWin)
    {
        cout << "Griffy" << "\n";
    }
    else if (!oWin && xWin)
    {
        cout << "Timothy" << "\n";
    }
    else if (oWin && xWin)
    {
        cout << "Error, redo" << "\n";
    }
    else if (!oWin && !xWin)
    {
        cout << "Tie" << "\n";
    }
}