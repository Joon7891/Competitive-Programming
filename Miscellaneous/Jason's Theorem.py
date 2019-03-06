mod = 10 ** 9 + 7

def get(n):
  power = 2
  count = 1

  while n > 0:
    if n & 1 > 0:
      count = (count * power) % mod
    
    power = (power * power) % mod
    n >>= 1
  
  for i in range(3):
    count = (2 * count) % mod

  return count - 5

print(get(int(input())))
