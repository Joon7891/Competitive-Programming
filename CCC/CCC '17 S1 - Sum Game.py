n = int(input())
a = [int(x) for x in input().split()]
b = [int(x) for x in input().split()]

a_sum, b_sum = 0, 0
k = 0
for i in range(n):
  a_sum += a[i]
  b_sum += b[i]

  if a_sum == b_sum:
    k = i + 1

print(k)