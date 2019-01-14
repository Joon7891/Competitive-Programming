r, x, y = map(int, input().split())

xs, ys, ms = [], [], []
for i in range(3):
    xn, yn, mn = map(int, input().split())
    xs.append(xn)
    ys.append(yn)
    ms.append(mn)

i = ms.index(min(ms))

if (x - xs[i]) ** 2 + (y - ys[i]) ** 2 < r * r:
    print('What a beauty!')
else:
    print('Time to move my telescope!')
