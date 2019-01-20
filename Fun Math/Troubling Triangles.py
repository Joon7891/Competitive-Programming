def get_distance(x_1, y_1, x_2, y_2):
  return ((x_1 - x_2) ** 2 + (y_1 - y_2) ** 2) ** 0.5

def area(a, b, c):
  s = (a + b + c) / 2

  return (s * (s - a) * (s - b) * (s - c)) ** 0.5

n = int(input())

for i in range(n):
  a_x, a_y, b_x, b_y, c_x, c_y = map(int, input().split())

  ab = get_distance(a_x, a_y, b_x, b_y)
  bc = get_distance(c_x, c_y, b_x, b_y)
  ac = get_distance(a_x, a_y, c_x, c_y)

  p = round(ab + bc + ac, 2)
  a = round(area(ab, bc, ac), 2)

  print('{0:0.2f}'.format(a) + ' ' + '{0:0.2f}'.format(p))
