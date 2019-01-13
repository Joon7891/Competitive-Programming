y_size, x_size = 0, 0
def in_maze(x, y):
  return -1 < x and x < x_size and -1 < y and y < y_size

def execute(maze):
  to_visit = [[0, 0]]
  visited = []
  
  length = 1

  while len(to_visit) > 0:
    new_to = []
    for node in to_visit:
      x, y = node[0], node[1]

      #Check
      if x == x_size - 1 and y == y_size - 1:
        return length
    
    #Up
      if (maze[y][x] == '+' or maze[y][x] == '|') and in_maze(x, y - 1) and not [x, y - 1] in visited and maze[y - 1][x] != '*':
        if not [x, y - 1] in new_to:
          new_to.append([x, y - 1])
      
      #Down
      if (maze[y][x] == '+' or maze[y][x] == '|') and in_maze(x, y + 1) and not [x, y + 1] in visited and maze[y + 1][x] != '*':
        if not [x, y + 1] in new_to:
          new_to.append([x, y + 1])
      
      #Right
      if (maze[y][x] == '+' or maze[y][x] == '-') and in_maze(x + 1, y) and not [x + 1, y] in visited and maze[y][x + 1] != '*':
        if not [x + 1, y] in new_to:
          new_to.append([x + 1, y])
      
      #Left
      if (maze[y][x] == '+' or maze[y][x] == '-') and in_maze(x - 1, y) and not [x - 1, y] in visited and maze[y][x - 1] != '*':
        if not [x - 1, y] in new_to:
          new_to.append([x - 1, y])

    visited.append([x, y])
    to_visit = new_to[:]
    length += 1

  return -1

n = int(input())

for i in range(n):
  y_size = int(input())
  x_size = int(input())
  maze = []
  for i in range(y_size):
    maze.append([char for char in input()])
  
  print(execute(maze))