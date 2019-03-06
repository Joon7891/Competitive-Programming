n = int(input())

f = n // 2
t = 2 * (f * (f + 1))

if n % 2 == 0:
  t -= n

print(t)