n = int(input())
a = [int(x) for x in input().split()]
a.sort()
mid = n // 2

if n % 2 == 0:
    high = a[mid:]
    low = a[:mid]
else:
    high = a[mid + 1:]
    low = a[:mid + 1]

low.sort(reverse = True)
final = []

for i in range(mid):
    final.append(low[i])
    final.append(high[i])

if n % 2 == 1:
    final.append(low[len(low) - 1])

print(*final)