def solve(a, b, c):
  if a.startswith(b) or b.startswith(a) or a.startswith(c) or c.startswith(a) or b.startswith(c) or c.startswith(b):
    return False

  if a.endswith(b) or b.endswith(a) or a.endswith(c) or c.endswith(a) or b.endswith(c) or c.endswith(b):
    return False
  
  return True

n = int(input())

for _ in range(n):
  a = input()
  b = input()
  c = input()

  if solve(a, b, c):
    print('Yes')
  else:
    print('No')