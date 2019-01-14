buses = []
n, m, h = map(int, input().split())
for i in range(n):
  buses.append(int(input()))

count = 0
for i in range(n - 1):
  while buses[n - i - 1] - buses[n - i - 2] > h:
    buses[n - i - 2] += m
    count += 1

print(count)