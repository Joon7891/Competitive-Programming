friends = {}
n = 0

def path_finding(current, end):
  visited = []

  d = -1

  while current != end and not current in visited:
    visited.append(current)
    d += 1
    current = friends[current]
  
  if current == end:
    return True, d
  else:
    return False, -1

n = int(input())
for i in range(n):
  x, y = map(int, input().split())
  friends[x] = y

a, b = -1, -1

while True:
  a, b = map(int, input().split())

  if a == 0 and b == 0:
    break
  else:
    path, length = path_finding(a, b)

    if path:
      print('Yes ' + str(length))
    else:
      print('No')
