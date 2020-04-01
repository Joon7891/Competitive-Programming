#include <bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int main()
{
    double x1, y1, x2, y2, x3, y3, x4, y4;
    double m1, m2, b1, b2;

    std::cin >> x1 >> y1 >> x2 >> y2;

    std::cin >> x3 >> y3 >> x4 >> y4;

    if (x1 == x2) m1 = INF;
    else m1 = (y1 - y2) / (x1 - x2);

    if (x3 == x4) m2 = INF;
    else m2 = (y3 - y4) / (x3 - x4);

    if (abs(m1 - m2) < 1e-6){
        if (m1 == INF){
            if (x1 == x3) cout << "coincident" << endl;
            else cout << "parallel" << endl;
        }
        else {
            if (abs(((x3 - x2) * m1 + y2) - y3) < 1e-6){
                cout << "coincident" << endl;
            }
            else cout << "parallel" << endl;
        }
    }
    else{
        b1 = y1 - m1 * x1;
        b2 = y3 - m2 * x3;

        long double x, y;
        if (m1 == INF){
            x = x1;
            y = m2 * x + b2;
        }
        else if (m2 == INF){
            x = x3;
            y = m1 * x + b1;
        }
        else {
            x = (b1 - b2) / (m2 - m1);
            y = m1 * x + b1;
        }

        cout << setprecision(6) << fixed << x << " " << y << endl;
    }
}