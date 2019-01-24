def price(n, y1, y2, y3, y4):
  k = (y1 * 12 + y2 * 10 + y3 * 7 + y4 * 5)
  return k

for i in range(10):
  cost = int(input())
  y1, y2, y3, y4 = map(float, input().split())

  n = int(input())
  y1, y2, y3, y4 = int(n * y1), int(n * y2), int(n * y3), int(n * y4)


  p = price(n, y1, y2, y3, y4)

  if round(p)/ 2 >= cost:
    print('NO')
  else:
    print('YES')