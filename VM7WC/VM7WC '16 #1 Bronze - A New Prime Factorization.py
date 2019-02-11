n = int(input())

primeFactors = []

status = True
while status:
    for i in range(2, n + 1):
        if n % i == 0:
            primeFactors.append(i)
            n = int(n / i)
            break

    if n == 1:
        status = False

size = len(primeFactors)
for i in range(size):
    print(primeFactors[i])