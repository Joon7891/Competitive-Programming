n = int(input())

for _ in range(n):
  line = input()

  prev = ''
  counter = 0
  for char in line:
    if char != prev:
      if prev != '':
        print(counter, prev, end = ' ')
      
      prev = char
      counter = 1
    else:
      counter += 1
  
  print(counter, prev)