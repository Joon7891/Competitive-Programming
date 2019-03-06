w = int(input())
h = int(input())

for i in range(h):
  output = str()
  for j in range(w):
    if (i + j) % 2 == 0:
      output += '0'
    else:
      output += '1'
  
  print(output)