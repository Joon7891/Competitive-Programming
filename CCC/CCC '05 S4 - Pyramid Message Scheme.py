l = int(input())

for i in range(l):
  n = int(input())
  connections = []
  tree = {}

  for j in range(n):
    connections.append(input())
  
  beg = connections[len(connections) - 1]
  for i in range(n):
    if i == 0:
      send, rec = beg, connections[0]
    else:
      send, rec = connections[i - 1], connections[i]

    if not send in tree.keys():
      tree[send] = [rec]
    else:
      if not rec in tree[send]:
        tree[send].append(rec)
    
    if not rec in tree.keys():
      tree[rec] = [send]
    else:
      if not send in tree[rec]:
        tree[rec].append(send)
  
  #Getting length
  to_visit = [beg]
  distances = {}
  for key in tree.keys():
    distances[key] = -1

  max_d = 0
  distances[beg] = 0
  while (len(to_visit)) > 0:
    top = to_visit[0]
    for node in tree[top]:
      if distances[node] == -1:
        to_visit.append(node)
        distances[node] = distances[top] + 1
        max_d = max(max_d, distances[node])


    to_visit.remove(top)

  print(max(0, n * 10 - 2 * max_d * 10))
