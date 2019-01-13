import sys
raw_input = sys.stdin.readline

def bfs(edges, n, p, q):
  visited = [False] * n

  to_eval = []

  to_eval.extend(edges[p])

  while len(to_eval) > 0:
    node = to_eval.pop(0)

    if node == q:
      return True
    
    if not visited[node]:
      visited[node] = True
      to_eval.extend(edges[node])
  
  return False

n, m = map(int, raw_input().split())

#Maps node 1 to 2 - directional edge
edges = []
for i in range(n):
  edges.append([])

for i in range(m):
  tall, short = map(int, raw_input().split())
  tall -= 1
  short -= 1

  edges[tall].append(short)

p, q = map(int, raw_input().split())
p -= 1
q -= 1


if bfs(edges, n, p, q):
    print('yes')
elif bfs(edges, n, q, p):
    print('no')
else:
    print('unknown')
