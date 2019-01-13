def num_divisors(n):
  count = 0
  for i in range(1, n + 1):
    if n % i == 0:
      count += 1
  
  return count

bottom = int(input())
top = int(input())

count = 0
for i in range(bottom, top + 1):
  if num_divisors(i) == 4:
    count += 1

print('The number of RSA numbers between {} and {} is {}'.format(bottom, top, count))
