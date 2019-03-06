from math import ceil

def is_prime(n):
  if n < 2:
    return False
  elif n == 2:
    return True

  m = ceil(n ** 0.5)
  for i in range(2, m + 1):
      if n % i == 0:
          return False
  
  return True

n = int(input())

while True:
    if is_prime(n):
        print(n)
        break
    
    else:
        n += 1