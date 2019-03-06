lineA = input().split(' ')
n, m = int(lineA[0]), int(lineA[1])

if n % m == 0:
    print('yes', int(n/m))
else:
    for i in range(m + 1, n + 1):
        if n % i == 0:
            print('no', (i - m))
            break