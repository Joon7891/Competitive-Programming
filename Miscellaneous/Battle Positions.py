i = int(input())
n = int(input())
j = int(input())

dif_array = [0] * (i + 1)

for a in range(j):
    x1, x2, k = map(int, input().split())
    dif_array[x1 - 1] += k
    dif_array[x2] -= k

total = 0
current = 0
for a in range(i):
    current += dif_array[a]
    if current < n:
        total += 1

print(total)