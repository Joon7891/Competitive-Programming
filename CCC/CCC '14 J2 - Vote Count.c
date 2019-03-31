#include <stdio.h>

const int MAXN = 20;
char votes[MAXN];
int N;

int main(void) 
{
  scanf("%i", &N);
  scanf("%s", &votes);

  int a = 0, b = 0;
  for (int i = 0; i < N; ++i)
  {
    if (votes[i] == 'A') ++a;
    else ++b;
  }

  if (a > b)
  {
    printf("A");
  }
  else if (a < b)
  {
    printf("B");
  }
  else
  {
    printf("Tie");
  }
}
