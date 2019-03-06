results = []

n = int(input())
for i in range(n):
  a, b, p = map(int, input().split())

  if a * b == p:
    results.append('POSSIBLE DOUBLE SIGMA')
  else:
    results.append('16 BIT S/W ONLY')

for result in results:
  print(result)
