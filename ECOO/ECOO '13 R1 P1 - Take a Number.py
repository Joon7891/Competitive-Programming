n = int(input())
late = 0
s = 0
word = input()
while word != 'EOF':
  if word == 'TAKE':
    n += 1
    late += 1

    if n == 1000:
      n = 1

  elif word == 'SERVE':
    s += 1
  
  elif word == 'CLOSE':
    print(late, late - s, n)
    late = 0
    s = 0

  word = input()
