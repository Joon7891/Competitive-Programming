n, k = map(int, input().split())
a = [int(x) for x in input().split()]
total = 0

p = n - 1
while k > 0 and p >= 0:
  if k / a[p] >= 0:
    total += int(k / a[p])
    k -= int(k / a[p]) * a[p]

  p -= 1

if k != 0:
  print(-1)
else:
  print(total)