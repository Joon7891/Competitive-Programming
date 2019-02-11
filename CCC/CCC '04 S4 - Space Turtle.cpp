#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;
int sx, sy, sz;
int tx, ty, tz;

const int POS_X = 1;
const int NEG_X = -1;
const int POS_Y = 2;
const int NEG_Y = -2;
const int POS_Z = 3;
const int NEG_Z = -3;

int on_top = POS_Z, on_left = POS_Y, on_front = POS_X;
int buf_top = POS_Z, buf_left = POS_Y, buf_front = POS_X;

int get_distance()
{
    return (sx - tx) * (sx - tx) + (sy - ty) * (sy - ty) + (sz - tz) * (sz - tz);
}

int main()
{
    cin >> sx >> sy >> sz;
    cin >> tx >> ty >> tz;

    int best = INF;
    while (true)
    {
        int d; char c;
        cin >> d >> c;

        // TO DO : Move Logic
        switch (on_front)
        {
        case POS_X:
            while (d--)
            {
                sx++;
                best = min(get_distance(), best);
            }

            break;

        case NEG_X:
            while (d--)
            {
                sx--;
                best = min(get_distance(), best);
            }

            break;

        case POS_Y:
            while (d--)
            {
                sy++;
                best = min(get_distance(), best);
            }

            break;

        case NEG_Y:
            while (d--)
            {
                sy--;
                best = min(get_distance(), best);
            }

            break;

        case POS_Z:
            while (d--)
            {
                sz++;
                best = min(get_distance(), best);
            }

            break;

        case NEG_Z:
            while (d--)
            {
                sz--;
                best = min(get_distance(), best);
            }

            break;
        }

        best = min(get_distance(), best);

        if (c == 'E') break;

        switch (c)
        {
        case 'L':
            buf_front = on_left;
            buf_left = -on_front;

            break;

        case 'R':
            buf_front = -on_left;
            buf_left = on_front;
            break;

        case 'U':
            buf_top = -on_front;
            buf_front = on_top;

            break;

        case 'D':
            buf_top = on_front;
            buf_front = -on_top;

            break;
        }

        on_left = buf_left;
        on_top = buf_top;
        on_front = buf_front;
    }

    float ans = ((int)(100 * sqrt(best * 1.0f) + 0.5)) / 100.0f;
    cout << setprecision(2) << fixed << ans << endl;
}