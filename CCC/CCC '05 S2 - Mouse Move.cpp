#include <iostream>
#include <cstdio>
#include <math.h>

using namespace std;

int main() {
  int c, r;
  scanf("%i %i", &c, &r);

  bool exitFlag = false;

  int currentX = 0;
  int currentY = 0;

  int x, y;
  while (!exitFlag)
  {
    scanf("%i %i", &x, &y);

    if (x == 0 && y == 0)
    {
      break;
    }

    currentX += x;
    currentY += y;

    if (currentX < 0)
    {
      currentX = 0;
    }
    else if (currentX > c)
    {
      currentX = c;
    }

    if (currentY < 0)
    {
      currentY = 0;
    }
    else if (currentY > r)
    {
      currentY = r;
    }

    cout << currentX << " " << currentY << endl;
  }
}