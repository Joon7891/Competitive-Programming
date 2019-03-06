points = []
n = int(input())
for i in range(n):
  x, y = map(int, input().split())
  dist = x ** 2 + y ** 2
  points.append([dist, x, y])

points.sort(reverse=True)
print(str(points[0][1]) + ' ' + str(points[0][2]))