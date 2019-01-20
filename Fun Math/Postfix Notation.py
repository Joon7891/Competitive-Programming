def get_val(word):
  s = []
  c = word.split(' ')

  for char in c:
    if char.isdigit():
      s.append(int(char))
    else:
      b = s.pop()
      a = s.pop()

      if char == '+':
        s.append(a + b)
      elif char == '-':
        s.append(a - b)
      elif char == '*':
        s.append(a * b)
      elif char == '/':
        s.append(a / b)
      elif char == '%':
        s.append(a % b)
      elif char == '^':
        s.append(a ** b)

  return s.pop()

val = get_val(input())
print('{0:0.1f}'.format(val))
