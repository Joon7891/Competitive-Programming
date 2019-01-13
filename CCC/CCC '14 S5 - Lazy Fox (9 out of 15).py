points = [[0, 0]]
n = int(input())
for i in range(n):
  x, y = map(int, input().split())
  points.append([x, y])

distance_pairs = []
for i in range(n + 1):
  for j in range(i, n + 1):
    dx = points[i][0] - points[j][0]
    dy = points[i][1] - points[j][1]
    distance_pairs.append([dx ** 2 + dy ** 2, i, j])

distance_pairs.sort()

best  = [0] * (n+1)
pbest = [0] * (n+1)
pdist = [0] * (n+1)

for pair in distance_pairs:
    d = pair[0]
    a = pair[1]
    b = pair[2]

    if d != pdist[a]:
        pdist[a] = d
        pbest[a] = best[a]
    if d != pdist[b]:
        pdist[b] = d
        pbest[b] = best[b]

    if a == 0: # the origin is a special case because we cannot revisit it
        best[a] = max(best[a], pbest[b])
    else:
        best[a] = max(best[a], pbest[b] + 1)
        best[b] = max(best[b], pbest[a] + 1)    

print(best[0])
