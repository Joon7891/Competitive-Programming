k = int(input())
mx = float(input())

total = 0
for i in range(k):
    line = [float(x) for x in input().split()][1:]
    total += sum(line)

print(total / k + mx)