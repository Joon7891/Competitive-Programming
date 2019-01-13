n = int(input())

a, b = [], []

for i in range(n):
    a.append(input())

for i in range(n):
    b.append(input())

count = 0
for i in range(n):
    if a[i] == b[i]:
        count += 1

print(count)
