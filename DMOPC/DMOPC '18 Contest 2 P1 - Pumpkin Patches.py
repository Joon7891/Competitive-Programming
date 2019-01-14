n = int(input())
x_points, y_points = [], []
for i in range(n):
  x, y = map(int, input().split())
  x_points.append(x)
  y_points.append(y)

length = 2 * (max(x_points) - min(x_points) + max(y_points) - min(y_points))
print(int(length))