n = int(input())
okay = [int(x) for x in input().split()]

a = set()
a.add(0)
counter = n
for i in range(n):
    k = okay[i]

    if not k in a:
        counter -= 1
        a.add(k)

print(counter)