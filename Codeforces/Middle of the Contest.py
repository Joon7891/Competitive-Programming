def to_time(t):
    h = t // 60
    m = t % 60

    if h < 10:
        h = '0' + str(h)
    else:
        h = str(h)

    if m < 10:
        m = '0' + str(m)
    else:
        m = str(m)

    return h + ':' + m

a = input()
b = input()

t1 = int(a[0:2]) * 60 + int(a[3:5])
t2 = int(b[0:2]) * 60 + int(b[3:5])
t3 = (t1 + t2) // 2

print(to_time(t3))