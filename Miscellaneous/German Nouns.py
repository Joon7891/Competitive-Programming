caps = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', "J", 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']

n = int(input())
for i in range(n):
  words = [char for char in input().split()]
  count = 0
  for word in words:
    if word[0] in caps:
      count += 1
  
  print(count)