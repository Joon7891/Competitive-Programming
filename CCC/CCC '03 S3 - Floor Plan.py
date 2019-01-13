from queue import Queue

floor = []
r, c = 0, 0

def in_grid(y, x):
  return -1 < y and y < r and -1 < x and x < c

def fill(rn, cn):
  q = Queue()
  q.put((rn, cn))

  size = 0

  floor[rn][cn] = 'I'
  while q.qsize() > 0:
    y, x = q.get()
    size += 1

    if in_grid(y - 1, x) and floor[y - 1][x] != 'I':
      q.put((y - 1, x))
      floor[y - 1][x] = 'I'
    
    if in_grid(y + 1, x) and floor[y + 1][x] != 'I':
      q.put((y + 1, x))
      floor[y + 1][x] = 'I'

    if in_grid(y, x + 1) and floor[y][x + 1] != 'I':
      q.put((y, x + 1))
      floor[y][x + 1] = 'I'

    if in_grid(y, x - 1) and floor[y][x - 1] != 'I':
      q.put((y, x - 1))
      floor[y][x - 1] = 'I'
  
  return size

n = int(input())
r = int(input())
c = int(input())
for i in range(r):
  floor.append(list(input()))

rooms = []
for i in range(r):
  for j in range(c):
    if floor[i][j] == '.':
      rooms.append(fill(i, j))

rooms.sort(reverse = True)

count = 0
for room in rooms:
  if n - room >= 0:
    count += 1
    n -= room
  else:
    break

if count == 1:
    print(str(count) + ' room, ' + str(n) + ' square metre(s) left over')
else:
    print(str(count) + ' rooms, ' + str(n) + ' square metre(s) left over')
