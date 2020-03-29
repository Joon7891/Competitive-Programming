#include <bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

struct sensor
{
    string type;
    int low, high;

    sensor(string type, int low, int high) : type(type), low(low), high(high) {}
};

struct measure
{
    int low, high;

    measure(int low, int high) : low(low), high(high) {}
};

vector<sensor> sensors;
vector<measure> measures;

int main()
{
    freopen("traffic.in", "r", stdin);
    freopen("traffic.out", "w", stdout);

    int N;
    cin >> N;

    string type; int low, high;
    measures.push_back(measure(0, INF));
    for (int i = 0; i < N; ++i)
    {
        cin >> type >> low >> high;
        sensors.push_back(sensor(type, low, high));

        if (type == "none")
        {
            measures.push_back(measure(low, high));
        }
        else
        {
            measures.push_back(measure(0, INF));
        }
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = i; j < N; ++j)
        {
            if (sensors[j].type == "none")
            {
                measures[j + 1].low = max(measures[j + 1].low, measures[j].low);
                measures[j + 1].high = min(measures[j + 1].high, measures[j].high);
            }
            else if (sensors[j].type == "off")
            {
                measures[j + 1].low = max(measures[j + 1].low, measures[j].low - sensors[j].high);
                measures[j + 1].high = min(measures[j + 1].high, measures[j].high - sensors[j].low);
            }
            else if (sensors[j].type == "on")
            {
                measures[j + 1].low = max(measures[j + 1].low, measures[j].low + sensors[j].low);
                measures[j + 1].high = min(measures[j + 1].high, measures[j].high + sensors[j].high);
            }
        }

        for (int j = i; j >= 0; --j)
        {
            if (sensors[j].type == "none")
            {
                measures[j].low = max(measures[j].low, measures[j + 1].low);
                measures[j].high = min(measures[j].high, measures[j + 1].high);
            }
            else if (sensors[j].type == "off")
            {
                measures[j].low = max(measures[j].low, measures[j + 1].low + sensors[j].low);
                measures[j].high = min(measures[j].high, measures[j + 1].high + sensors[j].high);
            }
            else if (sensors[j].type == "on")
            {
                measures[j].low = max(measures[j].low, measures[j + 1].low - sensors[j].high);
                measures[j].high = min(measures[j].high, measures[j + 1].high - sensors[j].low);
            }
        }
    }

    cout << measures[0].low << " " << measures[0].high << endl;
    cout << measures[N].low << " " << measures[N].high << endl;
}