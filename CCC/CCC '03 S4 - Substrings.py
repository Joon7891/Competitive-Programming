def longest(a, b):
  s = min(len(a), len(b))

  for i in range(s):
    if a[i:i+1] != b[i:i+1]:
      return i
  
  return s

n = int(input())

for i in range(n):
  word = input().strip()
  suffixes = []
  for j in range(len(word)):
    suffixes.append(word[j:])
  
  suffixes.sort()
  #print(suffixes)

  counter = len(suffixes[0]) + 1
  for j in range(1, len(word)):
    longe = longest(suffixes[j], suffixes[j - 1])
    counter += len(suffixes[j]) - longe
  
  print(counter)