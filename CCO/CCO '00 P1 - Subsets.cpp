#include <bits/stdc++.h>

using namespace std;

const int MAXN = 26 + 1;
map<char, vector<char> > graph;
vector<char> currentSets;

vector<char> getElements(char parent)
{
    vector<char> elements;
    vector<char> visited;
    queue<char> q; char current;
    q.push(parent);

    while (!q.empty())
    {
        current = q.front(); q.pop();

        if (graph.find(current) != graph.end())
        {
            for (int i = 0; i < graph[current].size(); ++i)
            {
                if (find(visited.begin(), visited.end(), graph[current][i]) == visited.end())
                {
                    if (islower(graph[current][i]))
                    {
                        elements.push_back(graph[current][i]);
                        visited.push_back(graph[current][i]);
                    }
                    else
                    {
                        q.push(graph[current][i]);
                        visited.push_back(graph[current][i]);
                    }
                }
            }
        }
    }

    return elements;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    char parent, child;
    string buffer;
    while (n--)
    {
        cin >> parent >> buffer >> child;
        graph[parent].push_back(child);

        if (find(currentSets.begin(), currentSets.end(), parent) == currentSets.end())
        {
            currentSets.push_back(parent);
        }

        if (find(currentSets.begin(), currentSets.end(), child) == currentSets.end() && isupper(child))
        {
            currentSets.push_back(child);
        }
    }

    sort(currentSets.begin(), currentSets.end());
    vector<char> current;

    for (int i = 0; i < currentSets.size(); ++i)
    {
        current = getElements(currentSets[i]);
        sort(current.begin(), current.end());

        cout << currentSets[i] << " = {";

        for (int i = 0; i < current.size(); ++i)
        {
            if (i + 1 == current.size())
            {
                cout << current[i];
            }
            else
            {
                cout << current[i] << ",";
            }
        }

        cout << "}\n";
    }
}