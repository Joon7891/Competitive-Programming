cur = int(input())
total = 0
n = cur
for i in range(cur):
  total += int(input())

new = int(input())
for i in range(new):
  n += 1
  total += int(input())
  av = round(total / n, 3)
  print('{0:0.3f}'.format(av))
