#include <iostream>

using namespace std;

int main() 
{
  int n, planes;
  cin >> n;
  cin >> planes;

  int ports[n + 1];
  for (int i = 0; i < n + 1; ++i)
  {
    ports[i] = 0;
  }

  bool openStatus = true;
  int newPlane;

  int toAdd;
  int total;
  for (int i = 0; i < planes; ++i)
  {
    if (!openStatus)
    {
      break;
    }

    cin >> newPlane;

    while (newPlane > 0 && ports[newPlane] > 0)
    {
      toAdd = ports[newPlane];
      ports[newPlane] += 1;
      newPlane -= toAdd;
    }

    if (newPlane <= 0)
    {
      openStatus = false;
    }
    else
    {
      ports[newPlane] = 1;
      total += 1;
    }
  }

  cout << total;
}