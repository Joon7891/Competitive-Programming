n, mi, ma = map(int, input().split())
h = [int(x) for x in input().split()]
count = len([x for x in h if x >= mi and x <= ma])
print(count)