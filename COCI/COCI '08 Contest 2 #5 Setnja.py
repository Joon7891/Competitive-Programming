walk = input()

ans, add = 1, 1
for char in walk:
  if char == 'L':
    ans *= 2
  elif char == 'R':
    ans = 2 * ans + add
  elif char == '*':
    ans = 5 * ans + add
    add = 3 * add
  
print(ans)