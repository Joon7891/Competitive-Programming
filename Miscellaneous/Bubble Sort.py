def output(a):
  size = len(a)
  final = str()
  for i in range(size):
    final += str(a[i]) + ' '
  
  return final.strip()

n = int(input())
a = [int(x) for x in input().split()]

print(output(a))
for i in range(n):
  for j in range(n - 1):
    if a[j] > a[j + 1]:
      swap = a[j]
      a[j] = a[j + 1]
      a[j + 1] = swap

      print(output(a))
