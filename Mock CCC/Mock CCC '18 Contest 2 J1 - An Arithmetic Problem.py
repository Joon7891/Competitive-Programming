lineA = input().split(' ')
a, b, c = int(lineA[0]), int(lineA[2]), int(lineA[4])

if a + b == c:
    print('True')
else:
    print('False')