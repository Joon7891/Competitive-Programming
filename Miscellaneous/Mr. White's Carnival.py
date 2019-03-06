n = int(input())
factors = 0
for i in range(1, n + 1):
  if n % i == 0:
    factors += i
  
print(factors)