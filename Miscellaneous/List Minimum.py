n = int(input())
a = []

for i in range(n):
    a.append(int(input()))

a.sort()

for i in range(n):
    print(a[i])
