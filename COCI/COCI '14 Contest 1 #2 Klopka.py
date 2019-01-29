n = int(input())

xs, ys = [], []
for i in range(n):
    x, y = map(int, input().split())
    xs.append(x)
    ys.append(y)

xd = max(xs) - min(xs)
yd = max(ys) - min(ys)
d = max(xd, yd) ** 2
print(d)