n = int(input())
a = [int(x) for x in input().split()]
b = [int(x) for x in input().split()]

d = []
for i in range(n):
  d.append(a[i] - b[i])

total = [0] * n
if n >= 1:
  if d[0] > 0:
    total[0] = d[0]

if n >= 2:
  if d[1] > 0:
    total[1] = d[1] + total[0]
  else:
    total[1] = total[0]

if n > 2:
  if d[2] > 0:
    total[2] = max(total[1], d[1] + d[2], total[0] + d[2])
  else:
    total[2] = total[1]

for i in range(3, n):
  if d[i] > 0:
    total[i] = max(total[i - 1], total[i - 2] + d[i], d[i] + d[i - 1] + total[i - 3])
  else:
    total[i] = total[i - 1]

print(total[n - 1] + sum(b))