board = 8 * [8 * [0]]
to_eval = []
x_f, y_f = 0, 0

moves = [
  [1, 2],
  [2, 1],
  [-1, -2],
  [-2, -1],
  [1, -2],
  [-2, 1],
  [-1, 2],
  [2, -1]
]

def in_board(x, y):
  return x >= 0 and x < 8 and y >= 0 and y < 8

def cycle(nodes):
  size = len(nodes)
  new_loc = 2 * [0]
  next_nodes = []
  for i in range(size):
    for j in range(8):
      new_loc[0] = nodes[i][0] + moves[j][0]
      new_loc[1] = nodes[i][1] + moves[j][1]
      if in_board(new_loc[0], new_loc[1]) and board[new_loc[0]][new_loc[1]] == 0:
        if new_loc[0] == x_f and new_loc[1] == y_f:
          return True
        else:
          board[new_loc[0]][new_loc[1]] == 1
          inst = new_loc
          next_nodes.append(inst[:])

  return next_nodes

exit_flag = False
initial_node = [int(x) - 1 for x in input().split()]
line = [int(x) - 1 for x in input().split()]
x_f, y_f = line[0], line[1]

if initial_node[0] == x_f and initial_node[1] == y_f:
  exit_flag = True

length = 0
nodes = [initial_node]
while not exit_flag:
  length += 1

  nodes = cycle(nodes)
  if nodes == True:
    exit_flag = True

print(length)
